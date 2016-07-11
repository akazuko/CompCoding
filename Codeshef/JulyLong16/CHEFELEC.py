r=raw_input
for t in xrange(int(r())):
	n = int(r())
	presence = r()
	coordinates = map(int, r().split())
	
	# ones = []
	# for i in len(n):
	# 	if presence[i] == '1':
	# 		ones.append(coordinates[i])
	# ans = 0
	# noo = len(ones)
	# for ind in xrange(noo):
	# 	if ind == 0:
	# 		ans += coordinates[ind] - coordinates[0]
	# 	elif ind == noo:
	# 		pass
	# 	else:
	# 		ld = 

	ans = 0

	ld = [float('inf')] * n
	rd = [float('inf')] * n

	i = 0
	while i < n:
		while i < n and presence[i] != '1':
			i+=1
		lone = coordinates[i]
		i+=1
		while i<n and presence[i]=='0':
			ld[i] = coordinates[i] - lone
			i+=1

	i = n-1
	while i >= 0:
		while i >=0 and presence[i] != '1':
			i-=1
		rone = coordinates[i]
		i-=1
		while i>=0 and presence[i]=='0':
			rd[i] = rone - coordinates[i]
			i-=1

	pos = [''] * n

	for i in xrange(n):
		if ld[i] < rd[i]:
			pos[i] = 'l'
		else:
			pos[i] = 'r'

	
	for i in xrange(n):
		if presence[i] == '1':
			continue
		if pos[i] == 'l':
			ans += coordinates[i] - coordinates[i-1]
		else:
			ans += coordinates[i+1] - coordinates[i]

	print ans