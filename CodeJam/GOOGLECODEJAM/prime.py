# for i in range(11111111111111111111111111111112):
def checkprime(m):
	f = int(m**0.5)
	for i in range(2,f):
		if m%i==0:
			return False
	return True
l={}
i=1
# while i < 11111111111111112:
	# if checkprime(i):
		# l[i] = 0
	# i+=1
print checkprime(11111111111111111)