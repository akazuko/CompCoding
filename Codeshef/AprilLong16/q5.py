r=raw_input
pval = 10**9+7

def multiply(F, M):
	x =  (((F[0][0]%pval)*(M[0][0]%pval))%pval + ((F[0][1]%pval)*(M[1][0]%pval))%pval)%pval
	y =  (((F[0][0]%pval)*(M[0][1]%pval))%pval + ((F[0][1]%pval)*(M[1][1]%pval))%pval)%pval
	z =  (((F[1][0]%pval)*(M[0][0]%pval))%pval + ((F[1][1]%pval)*(M[1][0]%pval))%pval)%pval
	w =  (((F[1][0]%pval)*(M[0][1]%pval))%pval + ((F[1][1]%pval)*(M[1][1]%pval))%pval)%pval

	# return list([[x%pval, y%pval], [z%pval, w%pval]])
	return [[x, y], [z, w]]

def power(F,n):
	ans = [[1,0],[0,1]]
	while n>0:
		if(n&1 == 1):
			ans = multiply(ans,F)
		F = multiply(F,F)
		n=n/2

	return ans
	
def Msum(F,M):
	x = ((F[0][0]%pval) + (M[0][0]%pval))%pval
	y = ((F[0][1]%pval) + (M[0][1]%pval))%pval
	w = ((F[1][0]%pval) + (M[1][0]%pval))%pval
	z = ((F[1][1]%pval) + (M[1][1]%pval))%pval

	# return list([[x%pval, y%pval],[w%pval, z%pval]])
	return [[x, y],[w, z]]


n,m=map(int,r().split())
l=map(int,r().split())

# To gen the tree
tree = [0 for _ in xrange(5*n)]
def build(node, start, end):
	if start==end:
		tree[node] = power([[1,1],[1,0]], l[start])
		# print node, tree[node]
	else:
		mid = (start + end)/2
		build(2*node, start, mid)
		build(2*node+1, mid+1, end)
		tree[node] = Msum( multiply(tree[2*node], tree[2*node+1]), Msum(tree[2*node], tree[2*node + 1]) )

def update(node, start, end, idx, val):
	if end < idx or start > idx:
		return
	if start==end:
		l[idx] = val
		tree[node] = power([[1,1],[1,0]], val)
	else:
		mid = (start+end)/2
		update(2*node, start, mid, idx, val)
		update(2*node +1, mid+1, end, idx, val)
		tree[node] = Msum( multiply(tree[2*node], tree[2*node+1]), Msum(tree[2*node], tree[2*node + 1]) )

def query(node, start, end, l, r):
	if start>end or start>r or end<l:
		return [[0,0],[0,0]]
	if l<=start and r>= end:
		return tree[node]
	mid = start + (end-start)/2
	p1 = query(2*node, start, mid, l, r)
	p2 = query(2*node+1, mid+1, end, l, r)
	# print p1, p2
	return Msum( multiply(p1,p2), Msum(p1,p2))

build(1,0,n-1)

for q in range(m):
	typ, x, y = r().split()
	x=int(x)
	y=int(y)
	if typ=='C':
		# print tree
		update(1,0,n-1,x-1,y)
		# print tree
	else:
		temp = query(1,0,n-1,x-1,y-1)
		#print temp
		print temp[0][1]%pval
