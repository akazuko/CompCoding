N,M=map(int,raw_input().split())
from collections import defaultdict
A=map(int,raw_input().split())

l=defaultdict(int)

for i in range(N):
	j=i
	while(j<N):
		if i==j:
			m=A[j]
			l[m]+=1
		else:
			if m < A[j]:
				m=A[j]
			l[m]+=1
		j+=1

ans=''
p=l.keys()

for i in range(M):
	d=raw_input().split()
	c=d[0]
	k=int(d[1])
	x=d[2]
	count=0
	if c=='<':
		for z in p:
			if z<k:
				count+=l[z]
	elif c=='>':
		for z in p:
			if z>k:
				count+=l[z]
	elif c=='=':
		for z in p:
			if z==k:
				count+=l[z]
	
	if x=='D':
		if count%2==0:
			ans+='C'
		else:
			ans+='D'
	else:
		if count%2==0:
			ans+='D'
		else:
			ans+='C'
print ans