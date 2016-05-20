T=int(raw_input())
for i in range(T):
	T1, T2, t1, t2 = map(float, raw_input().split())
	T1=T1*1.00000
	T2=T2*1.00000
	print '%.6f' %(((t1+t2)*(T2-t1-t2))/(T1*T2))
