t=1
r=raw_input
while 1:
	inp = r()
	if inp[0]=='-':
		break

	er = 0
	op = 0
	for i in inp:
		if i=='{':
			op+=1
		elif i=='}':
			op-=1
			if op<0:
				op = 1
				er+= 1
	print "%d. %d" %(t,(er+op/2))
	t+=1