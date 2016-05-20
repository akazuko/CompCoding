for i in range(int(raw_input())):
	n, k = map(int, raw_input().split())
	A=map(int,raw_input().split())
	B=map(int,raw_input().split())
	while(1):
		if k==0:
			break
		temp = list(A)
		temp.sort()
		temp=temp[::-1]
		while(k!=0 and temp!=[]):
			index = A.index(temp[0])
			if(B[index]<0 and temp[0]>0):
				temp.pop(0)
			else:
				if A[index]>0:
					A[index]+=1
				k-=1
				temp.pop(0)
	ans = 0
	for i in range(n):
		ans+=A[i]*B[i]
	print ans
