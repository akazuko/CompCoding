r=raw_input
for t in xrange(int(r())):
	num=r()
	palin=list(num)
	start = 0
	end = len(num)-1
	while start<=end:
		if palin[end]<palin[start]:
			palin[end] = palin[start]
		elif palin[end]>palin[start]:
			# temp = palin[end]
			palin[end] = palin[start]
			temp2 = ''.join(palin)
			print temp2
			if int(num)>=int(temp2):
				palin[start] = chr(ord(palin[start]) + 1)
				palin[end] = palin[start]
		start+=1
		end-=1
	print palin