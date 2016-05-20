for T in range(int(raw_input())):
	n,k=map(int,raw_input().split())
	l=map(int,raw_input().split())
	ans=[0]*(n+1)
	for i in range(n+1):
		ans[i]=[0]*(k+1)
	for i in range(1,n+1):
		for j in range(1,k+1):
			wi=l[i-1]
			bi=1
			if wi<=j:
				if bi+ans[i-1][j-wi]>ans[i-1][j]:
					ans[i][j]=bi+ans[i-1][j-wi]
				else:
					ans[i][j]=ans[i-1][j]
			else:
				ans[i][j]=ans[i-1][j]

	print ans[n][k]