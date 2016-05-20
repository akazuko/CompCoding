for T in range(int(raw_input())):
	l1=raw_input()
	l2=raw_input()
	i=0
	s1=len(l1)-1
	s2=len(l2)-1
	pos=[0,'']
	change=0
	ans=True
	#start
	if l1[i]=='.':
		pos[0]=i
		pos[1]='l1'
		# i+=1
	elif l2[i]=='.':
		pos[0]=i
		pos[1]='l2'
		# i+=1
	else:
		ans=False
	if ans:
		while(i<s1 and i<s2):
			if pos[1]=='l1':
				if i+1<=s1 and l1[i+1]=='.':
					i+=1
					pos[0]=i
				elif i<=s2 and l2[i]=='.':
					pos[0]=i
					pos[1]='l2'
					change+=1
				elif i+1<=s2 and l2[i+1]=='.':
					i+=1
					pos[0]=i
					pos[1]='l2'
					change+=1
				else:
					if i!=s1 or i!=s2:
						ans=False
						break
			elif pos[1]=='l2':
				if i+1<=s2 and l2[i+1]=='.':
					i+=1
					pos[0]=i
				elif i<=s1 and l1[i]=='.':
					pos[0]=i
					pos[1]='l1'
					change+=1
				elif i+1<=s1 and l1[i+1]=='.':
					i+=1
					pos[0]=i
					pos[1]='l1'
					change+=1
				else:
					if i!=s1 or i!=s2:
						ans=False
						break
	if ans:
		if pos[1]=='l1' and i<s1:
			while(i<=s1):
				if l1[i]!='.':
					ans=False
					break
				i+=1
		if pos[1]=='l2' and i<s2:
			while(i<=s2):
				if l2[i]!='.':
					ans=False
					break
				i+=1
		if pos[1]=='l2' and i==s2:
			if l2[i]=='.':
				ans=True
			else:
				ans=False
		if pos[1]=='l1' and i==s1:
			if l1[i]=='.':
				ans=True
			else:
				ans=False	
	
	if ans:
		print 'Yes'
		print change
	else:
		print 'No'	