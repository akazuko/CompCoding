r=raw_input
for _ in range(int(r())):
	n=int(r())
	s=r()
	x=0;
	y=0
	z=0
	for i in s:
		if i=='R':
			x+=1
		elif i=='G':
			y+=1
		elif i=='B':
			z+=1

	cost1 = y+z
	cost2 = z+x
	cost3 = x+y
	cost = min(cost1,cost2,cost3)
	if cost == cost1:
		print y+z
	elif cost == cost2:
		print x+z
	elif cost == cost3:
		print y+x