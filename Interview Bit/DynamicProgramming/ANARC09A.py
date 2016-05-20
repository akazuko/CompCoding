t=1
r=raw_input
while 1:
	inp = r()
	er = 0
	op = 0
	for i in inp:
		if i=='{':
			op+=1
		elif i=='}':
			if op==0:
				er+=1
			else:
				op-=1
	print "%d. %d" %(er/2,op/2)
	t+=1