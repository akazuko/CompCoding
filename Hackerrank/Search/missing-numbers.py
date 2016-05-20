from collections import defaultdict
n=int(raw_input())
l1=map(int,raw_input().split())
m=int(raw_input())
l2=map(int,raw_input().split())
ans=[]
ll1=defaultdict(int)
ll2=defaultdict(int)
if n!=m:
	for k in l1:
		ll1[k]+=1
	for k in l2:
		ll2[k]+=1

	k1 = ll1.keys()
	k2 = ll2.keys()

	if len(k1) > len(k2):
		for k in k1:
			if ll2[k] == 0:
				ans.append(k)
			elif ll1[k] != ll2[k]:
				ans.append(k)
	else:
		for k in k2:
			if ll1[k] == 0:
				ans.append(k)
			elif ll1[k] != ll2[k]:
				ans.append(k)

ans.sort()
answer = ''
for k in ans:
	answer+=str(k) + ' '
print answer