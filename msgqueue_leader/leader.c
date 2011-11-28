#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <mqueue.h>

#include <ocelot/analysis/interface/kernel_profile.h>

#define MQ_OPEN_OWNER_FLAGS		(O_RDWR | O_CREAT | O_EXCL | O_NONBLOCK)
//! Maximum number of messages allowed to queue up.
#define MQ_MAX_MESSAGES			8

//! Maximum message size allowable. Just set to the size of our structure.
#define MQ_MAX_MSG_SIZE			(sizeof(kernel_profile))

int main() {
 
    int err = 0;
    
    mqd_t msgQueue;
    struct mq_attr qattr;
    
    kernel_profile profile;
    
    qattr.mq_maxmsg = MQ_MAX_MESSAGES;
	qattr.mq_msgsize = MQ_MAX_MSG_SIZE;
    
retry_open:
    msgQueue = mq_open(MSG_QUEUE, MQ_OPEN_OWNER_FLAGS, 0664, &qattr);
    if(msgQueue < 0)
    {
		if (errno == EEXIST) {
			err = mq_unlink(MSG_QUEUE);
			if (err < 0) {
				printf("mq_unlink failed\n");
				exit(1);
			}
			goto retry_open;
		} else {
			printf("mq_open failed\n");
			exit(1);
		}
    }
    
    printf("Sleeping for 10 seconds ..\n");
    sleep(10);
    
    mq_getattr(msgQueue, &qattr);
    printf("%lu message(s) in queue\n", qattr.mq_curmsgs);
    
    if(qattr.mq_curmsgs != 0)
    {
	memset(&profile, 0, sizeof(profile));
        while((err = mq_receive(msgQueue, (char *)&profile, sizeof(kernel_profile), NULL)) > 0)
	{
            printf("pid: %d, device: %d, name: %s, type: %u, data: %lu\n", 
					profile.pid, profile.device, profile.name, profile.type, profile.data.kernel_runtime);    
        }    
    }
    
    mq_close(msgQueue);
    
    mq_unlink(MSG_QUEUE);
    
    return err;
}
