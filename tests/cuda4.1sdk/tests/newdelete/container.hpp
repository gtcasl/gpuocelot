/*
* Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
*
* Please refer to the NVIDIA end user license agreement (EULA) associated
* with this source code for terms and conditions that govern your use of
* this software. Any use, reproduction, disclosure, or distribution of
* this software and related documentation outside the terms of the EULA
* is strictly prohibited.
*
*/

#if defined(__x86_64) || defined(AMD64) || defined(_M_AMD64)
typedef unsigned long long int pointer_int_t;
#else
typedef unsigned int pointer_int_t;
#endif



/////////////////////////////////////////////////////////////////////////////
//
// Container parent class.
//
////////////////////////////////////////////////////////////////////////////


template<class T>
class Container {

public:
	__device__
	Container() {;}

	__device__
	virtual void push(T e) = 0;

	__device__
	virtual bool pop(T &e) = 0;
};

/////////////////////////////////////////////////////////////////////////////
//
// Vector class derived from Container class using linear memory as data storage
//
////////////////////////////////////////////////////////////////////////////


template<class T>
class Vector : public Container<T> {

public:
	// Constructor, data is allocated on the heap
	__device__
	Vector(int max_size) :  m_top(-1) {
		m_data = new T[max_size];
	}

	// Constructor, data uses preallocated buffer via placement new
	__device__
	Vector(int max_size, T* preallocated_buffer) :  m_top(-1) {
		m_data = new (preallocated_buffer) T[max_size];
	}

	__device__
	~Vector() {
		delete [] m_data;
	}

	__device__
	virtual
	void push(T e) {
		// Atomically increment the top idx
		int idx = atomicAdd(&(this->m_top), 1);
		m_data[idx+1] = e;
	}

	__device__
	virtual
	bool pop(T &e) {
		if( m_top >= 0 ) {
			// Atomically decrement the top idx
			int idx = atomicAdd( &(this->m_top), -1 );
			if( idx >= 0 ) {
				e = m_data[idx];
				return true;
			}
		}
		return false;
		
	}


private:
	int m_size;
	T* m_data;

	int m_top;
};


/////////////////////////////////////////////////////////////////////////////
//
// Stack classes derived from Container class using singly linked lists as data storage.
//
////////////////////////////////////////////////////////////////////////////


template<class T>
class SingleLinkElement {

public:
	__device__
	SingleLinkElement(T e) : m_data(e), m_next(0) {
	}

	__device__
	void setNext(SingleLinkElement<T>* next) {
		m_next = next;
	}

	__device__
	SingleLinkElement<T>* getNext() {
		return m_next;
	}

	__device__
	T operator() (){
		return m_data;
	}

private:
	T m_data;
	SingleLinkElement<T>* m_next;
};


template<class T>
class Stack : public Container<T> {

public:
	__device__
	Stack() {
		m_top = 0;
	}

	__device__
	virtual 	
	void push(T e) {
		// Create new List element on the device heap
		SingleLinkElement<T>* newElement = new SingleLinkElement<T>(e);

		// Atomic exchange to safely update the top of stack pointer and get the old top pointer 
		SingleLinkElement<T>* old_top = (SingleLinkElement<T>*) atomicExch( (pointer_int_t*)&(this->m_top),
                                                                                    (pointer_int_t)newElement );

		newElement->setNext(old_top);
	}

	__device__
	virtual
	bool pop(T &e) {
		// Get pointer to top element
		SingleLinkElement<T>* curr_top;
		SingleLinkElement<T>* next;
		SingleLinkElement<T>* old_top;

		curr_top = 0;
		old_top = this->m_top;

		while( old_top != 0 && old_top != curr_top ) {
			curr_top = old_top;

			// Otherwise get pointer to the next element in the list
			next = curr_top->getNext();
		
			// Update the top pointer to this one but ONLY if no other thread concurrently changed top in the meantime.
			// This is implemented with atomic compare and swap, comparing top with the value we read first. 
			// If there was a change they are not equal and we try again.
			old_top = (SingleLinkElement<T>*) atomicCAS( (pointer_int_t*)&(this->m_top), 
                                                                     (pointer_int_t)curr_top, 
                                                                     (pointer_int_t)next );
		}
		
		if( old_top != 0 ) {
			// Return the top element 
			e = (*old_top)();
			delete old_top;
			return true;
		} else {
			// Stack is empty
			return false;
		}
	}


protected:
	// Pointer to the top of the stack
	SingleLinkElement<T>* m_top;

};

