from Queue import Queue
ri=raw_input

T = int(ri())
for t in range(T):
	n,r,m = map(int,ri().split())
	
	g = [ [] for _ in range(n+1)]
	vis1 = [ 0 for _ in range(n+1)]

	for i in range(r):
		a,b = map(int,ri().split())
		g[a].append(b)
		g[b].append(a)
	
	for j in range(m):
		a,b = map(int,ri().split())

		vis2 = [ False for _ in range(n+1)]
		level = [ -1 for _ in range(n+1)]

		q1 = Queue()
		q2 = Queue()

		vis2[a] = True
		level[a] = 0;

		q1.put(a)
		q2.put(a)

		while(not q1.empty()):
			node = q1.get()

			if level[node] < b:
				continue

			for i in g[node]:
				if not vis2[i]:
					vis2[i] = True
					level[i] = level[node] + 1
					q1.put(i)
					q2.put(i)

		while(not q2.empty()):
			vis1[q2.get()]+=1

	ans = True

	for i in range(1,n):
		if vis1[i]==0 or vis1[i]>1:
			ans = False
			break

	if ans : 
		print "Yes"
	else:
		print "No"