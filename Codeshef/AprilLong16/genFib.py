def multiply(F, M):
	x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
	y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
	z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
	w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

	F[0][0] = x
	F[0][1] = y
	F[1][0] = z
	F[1][1] = w

def power(F,n):
	if n==1 or n==0:
		return
	M=[[1,1],[1,0]]
	power(F,n/2)
	multiply(F,F)
	if n%2!=0:
		multiply(F,M)

def fib(n):
	F=[[1,1],[1,0]]
	if n==0:
		return 0
	power(F,n-1)
	return F[0][0]

print fib(8)
print fib(10)
print fib(18)
# print fib(4)
# print fib(5)
# print fib(6)
# print fib(7)
# print fib(8)
# for i in range(8):
# 	print fib(i)