
import sys

columns = None

while 1:
	line = sys.stdin.readline()
	if not line:
		break
	contents = line.strip("\n").split(',')
	if columns == None:
		columns = [[] for x in range(0, len(contents))]
	for i, block in enumerate(contents):
		if block == 'x':
			block = -1
		columns[i].append(int(block))

counters = [0 for x in range(0, len(columns))]
reading = True
while reading:
	result = []
	endOfColumn = 0
	for i, column in enumerate(columns):
		while counters[i] < len(column) and column[counters[i]] < 0:
			counters[i] += 1
		if counters[i] < len(column):
			result.append(column[counters[i]])
			counters[i] += 1
		else:
			endOfColumn += 1
			result.append(-1)
	if endOfColumn > 0:
		reading = False
	else:	
		distinct = {}
		distinct[x] = True
		suffix = ""
		if len(distinct.keys()) > 1:
			suffix = "--NOT EQUAL--"
		print ",".join([str(x) for x in result]), suffix
			
			
		
