r=raw_input
for _ in range(int(r())):
	n,k=map(int, r().split())
	A = map(int, r().split())
	B = map(int, r().split())
	summ = 0
	mB  = 0
	for i in range(n):
		summ += A[i]*B[i]
		mB = max(mB, abs(B[i]))
	summ += mB*k
	print summ


