from collections import defaultdict
def c(s,n):
	if n%2==0:
		if n==2:
			if s[0]==s[1]:
				return 1
		if s[0:(n/2)]==s[(n/2):n]:
			return 1
	return 0

lk = defaultdict()

import time
start_time = time.time()

for i in range(int(raw_input())):
	s=raw_input()
	n=len(s)
	y=0
	dct=defaultdict()
	if s not in lk.keys():
		if c(s,n)==1:	
			y=1
		i=0
		while y!=1 and i<n:
			temp=list(s)
			temp.pop(i)
			l=''.join(temp)
			if l not in dct.keys():
				dct[l] = c(l,n-1)
				if dct[l]==1:
					y=1
					break
			i+=1
		if y==1:
			lk[s]="YES"
		else:
			lk[s]="NO"	
		print lk[s]
	else:
		print lk[s]
	 
print("--- %s seconds ---" % (time.time() - start_time))