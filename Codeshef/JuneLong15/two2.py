T=int(raw_input())
for i in range(T):
	T1, T2, t1, t2 = map(long, raw_input().split())
	temp=(T1+t1)*(T2+t2)
	temp=temp*1.0
	a1=0.5*(T1)*(T2+t2-t1)
	a2=0.5*(T2)*(T1+t1-t2)
	print 1-(a1 + a2)/temp
	# print prob