r = raw_input
n,k = map(int, r().split())
A = map(int, r().split())
l_inc = [0] * n
r_inc = [0] * n
l_dec = [0] * n
r_dec = [0] * n

for i in range(n):
	if i==0:
		l_inc[i] = 1
		l_dec[i] = 1
		continue

	if A[i] >= A[i-1]:
		l_inc[i] = l_inc[i-1] + 1
	else:
		l_inc[i] = 1

	if A[i] <= A[i-1]:
		l_dec[i] = l_dec[i-1] + 1
	else:
		l_dec[i] = 1

for i in range(n-1,-1,-1):
	if i==n-1:
		r_inc[i] = 1
		r_dec[i] = 1
		continue

	if A[i] >= A[i+1]:
		r_inc[i] = r_inc[i+1] + 1
	else:
		r_inc[i] = 1

	if A[i] <= A[i+1]:
		r_dec[i] = r_dec[i+1] + 1
	else:
		r_dec[i] = 1

inc = 0
dec = 0

for i in xrange(k-1):
	inc += l_inc[i]
	dec += l_dec[i]

for i in xrange(k-1, n):
	inc += min(k, l_inc[i])
	dec += min(k, l_dec[i])
	print inc-dec
	inc -= min(k, r_dec[i - (k-1)])
	dec -= min(k, r_inc[i - (k-1)])
