

import os
import shutil

def capitalize(X):
	
	if ord(X[0]) >= ord('a') and ord(X[0]) <= ord('z'):
		Y = chr(ord(X[0]) - ord('a') + ord('A'))
	else:
		Y = X[0]
	return str(Y) + X[1:]


copyData = False

applications = {}

contents = os.listdir(".")
for entry in contents:
	if os.path.isdir(entry):
		if entry == 'data':
			continue
		app = capitalize(entry)
		subdirs = [x for x in os.listdir(entry) if os.path.isdir(entry + "/" + x) and x != '.' and x != '..']
		files = [x for x in os.listdir(entry) if os.path.isfile(entry + "/" + x)]
		cuFiles = [x for x in files if x[-3:] == ".cu" ]
		cppFiles = [x for x in files if x[-4:] == ".cpp" ]
		
		applications[app] = (app, ",".join(["'" + x + "'" for x in cuFiles + cppFiles]), entry)
		
		for subdir in subdirs:
			if subdir in ('doc', 'obj'):
				shutil.rmtree(entry + '/' + subdir)
			elif subdir == 'data' and copyData:
				datafiles = os.listdir(entry + '/data')
				for datafile in datafiles:
					src = entry + '/data/' + datafile
					dst = 'data/' + datafile
					if os.path.isfile(dst):
						dst = 'data/' + entry + '-' + datafile
					shutil.copyfile(src, dst)
		
		for f in files:
			if f in ('Makefile', 'CMakeLists.txt', 'readme.txt'):
				os.remove(entry + '/' + f)

appNames = sorted(applications.keys())
for app in appNames:
	print "\t('%s', [%s,], '%s')," % applications[app]


