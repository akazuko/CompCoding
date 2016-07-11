R=raw_input

n,m = map(int, R().split())

arr = []

for i in range(n):
	arr.append(map(int, R().split()))

q = int(R())

for qq in range(q):
	a,b = map(int,R().split())
	temp = float('inf')
	for i in range(n):
		for j in range(m):
			if i+a>n or j+b>m:
				continue
			maxx = -1*float('inf')
			summ = 0
			for x in range(a):
				for y in range(b):
					maxx = max(maxx, arr[i+x][j+y])
					summ += arr[i+x][j+y]
			temp = min(temp, maxx*a*b - summ)
	print temp	