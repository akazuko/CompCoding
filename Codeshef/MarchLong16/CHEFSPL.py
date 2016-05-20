def check(s, n):
	if n==2:
		return s[0]==s[1]
	else:
		return s[:(n/2)]==s[n/2:]
for _ in range(int(raw_input())):
	s = raw_input()
	n =len(s)
	if n==1:
		print "NO"
	elif n%2==0:
		if check(s,n):
			print "YES"
		else:
			print "NO"
	else:
		i=0
		j=n/2
		if(s[0:n/2]==s[n/2+1:]):
			print "YES"
		else:
			#assuming on left
			i=0
			j=n/2+1
			count = 0
			while(i<=n/2 and j<n and count<=1):
				if s[i]==s[j]:
					i+=1
					j+=1
				else:
					count+=1
					i+=1
			# if(i==n/2+1 and j==n and count==1):
			if count<=1:
				print "YES"
			else:
				#assume it on right
				count = 0
				i=0
				j=n/2
				while(i<=n/2-1 and j<n and count<=1):
					# print "%s %s %d" %(s[i],s[j],count)
					if s[i]==s[j]:
						i+=1
						j+=1
					else:
						count+=1
						j+=1
				# if(i==n/2 and j==n and count==1):
				if count<=1:
					print "YES"
				else:
					print "NO"