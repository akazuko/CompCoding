rr=raw_input
for _ in range(int(rr())):
	r,g,b = map(int,rr().split())
	k=int(rr())
	ans=0
	ans+=min(k-1,r)
	ans+=min(k-1,g)
	ans+=min(k-1,b)
	print ans+1