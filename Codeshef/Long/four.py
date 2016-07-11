r=raw_input
req = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def baseval(k, base):
	ans = ""
	if k==0:
		return "0"
	while k>0:
		ans+=req[k%base]
		k = k/base
	return ans[::-1]
gg = '02468'
for t in range(int(r())):
	n = int(r())
	val = baseval(n-1,5)
	ans = ""
	for i in val:
		ans+=gg[int(i)]
	print ans