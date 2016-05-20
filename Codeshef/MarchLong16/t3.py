# from collections import defaultdict
def c(s,n):
	if n%2==0:
		if n==2:
			if s[0]==s[1]:
				return 1
		if s[0:(n/2)]==s[(n/2):n]:
			return 1
	return 0
def mo(s1,s2):
	if s1==s2:
		return 1
	return 0

# import time
# start_time = time.time()

for i in range(int(raw_input())):
	s=raw_input()
	n=len(s)
	y=0
	if n%2==0:
		if n==2:
			if s[0]==s[1]:
				print "YES"
				y=1
		if s[0:(n/2)]==s[(n/2):n]:
			print "YES"
			y=1
	else:
		for i in range(1,n-1):
			hav = s[0:i] + s[i+1:]
			hvl=len(hav)
			if c(hav, hvl) == 1:
				print "YES"
				y=1
				break
	if y!=1:
		print "NO"				
# print("--- %s seconds ---" % (time.time() - start_time))