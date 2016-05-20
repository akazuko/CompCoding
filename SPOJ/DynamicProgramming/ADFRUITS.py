import sys
r=raw_input
def lcs(s1,s2):
	n1 = len(s1)
	n2 = len(s2)
	dp = [ [0 for _ in range(n1+1)] for x in range(n2+1)]
	for i in range(n2+1):
		for j in range(n1+1):
		 	if i==0 or j==0:
		 		dp[i][j]=0
		 	elif s1[j-1]==s2[i-1]:
		 		dp[i][j] = dp[i-1][j-1] + 1 
		 	else:
		 		dp[i][j] = max(dp[i][j-1],dp[i-1][j])
	pos=[]
	i=n2
	j=n1
	while j>0 and i>0:
		if s2[i-1]==s1[j-1]:
			pos.append([j-1,i-1])
			i=i-1
			j=j-1
		elif dp[i-1][j] > dp[i][j-1]:
			i=i-1
		else:
			j=j-1
	pos.sort()
	# print pos
	return pos

while 1:
	# inp = sys.stdin.read()
	try:
		inp=r()
		s1,s2 = inp.split()
		n1 = len(s1)
		n2 = len(s2)
		if n1==0 and n2!=0:
			print s2
			continue
		elif n1!=0 and n2==0:
			print s1
			continue
		elif n1==0 and n2==0:
			print ""
			continue
		pos = lcs(s1,s2)
		if pos==[]:
			print s1+s2
			continue
		i=0
		j=0
		ans = ""
		pol = len(pos)
		# while i<len(s1) and j<len(s2):
		for i in range(pol):
			if i==0:
				ans += s1[0:pos[i][0]] + s2[0:pos[i][1]] + s1[pos[i][0]]
			else:
				ans += s1[pos[i-1][0]+1:pos[i][0]] + s2[pos[i-1][1]+1:pos[i][1]] + s1[pos[i][0]]
			# print i, ans, pos[i]
		# print pos[pol-1][0]+1,n1,pos[pol-1][1]+1,n2
		ans+=s1[pos[pol-1][0]+1:n1] + s2[pos[pol-1][1]+1:n2]
		print ans
	except EOFError:
		break