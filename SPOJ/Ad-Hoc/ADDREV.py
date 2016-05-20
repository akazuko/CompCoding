# your code goes here
r=raw_input
for i in range(int(r())):
	a,b = map(lambda x : int(x[::-1]), r().split())
	a = a+b
	print int(str(a)[::-1])