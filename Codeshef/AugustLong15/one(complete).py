from math import log

for T in range(int(raw_input())):
	v,u=map(int,raw_input().split())
	# u is final and V is initial
	ans=0
	
	if u==v:
		ans=0

	elif u>v:
		while( log(v,2)!=int(log(v,2)) ):
			v=v>>1
			ans+=1

		ans+=int(log(u,2)-log(v,2))

	elif u<v:

		while(log(v,2)!=int(log(v,2))):
			v=v>>1
			ans+=1
		if v>u:
			ans+=int(log(v,2)-log(u,2))
		else:
			ans+=int(log(u,2)-log(v,2))
	print ans