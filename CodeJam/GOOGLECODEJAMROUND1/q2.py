r=raw_input
for t in xrange(int(r())):
	n =  int(r())
	all_list = []
	for i in range(2*n-1):
		all_list.append(map(int,r().split()))
	all_list.sort()
	heads=all_list[0]
	arr = [[0 for p in range(n)] for _ in range(n)]
	for i in heads[1:]:
		for k in xrange(2*n-1):
			if all_list[k]!=[] and all_list[k][0] == i:
				all_list[k]=[]
				break
	i=0
	k=0
	print all_list
	while k<2*n-1:
		if all_list[k]==[]:
			k+=1
			continue
		arr[i] = all_list[k]
		print 'all', all_list[k]
		i+=1
		k+=1
	ans = ""
	print arr
	for i in range(n):
		ans+=str(arr[i][0]) + ' '
	print "Case #%d: %s" %(t+1, ans)
