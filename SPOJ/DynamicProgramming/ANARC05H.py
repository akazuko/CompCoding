r=raw_input
t=1
while 1:
	s=r()
	n=len(s)
	if s=="bye":
		break
	li=map(int, list(s))
	csum = [0] * n
	for i in range(1,n):
		csum[i] = csum[i-1] + li[i]
	dp = [[0] for _ in range(n+1)] for x in range(n+1)
	for i in range(1,n+1):
		for j in range(1,n+1):
			if 
