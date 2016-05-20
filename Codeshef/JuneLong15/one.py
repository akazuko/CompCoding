T=int(raw_input())
for i in range(T):
	N=int(raw_input())
	maxallo=0
	totalacco=0
	for j in map(int, raw_input().split(' ')):
		if j>maxallo:
			totalacco= totalacco+j-maxallo
			maxallo=j
		else:
			maxallo=j
	print totalacco