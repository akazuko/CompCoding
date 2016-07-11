r = raw_input
n,k = map(int, r().split())
A = map(int, r().split())

for start in range(n):
	end = start + k - 1
	if end >= n :
		break
	
	inc = 0
	dec = 0
	i = start + 1
	count = 1
	while i <= end:
		if A[i] >= A[i-1]:
			count+=1
		else:
			if count%2==0:
				inc += (count/2)*(count-1)
			else:
				inc += count*((count-1)/2)
			count = 1
		i+=1

	if count != 1:
		if count%2==0:
			inc += (count/2)*(count-1)
		else:
			inc += count*((count-1)/2)		

	i = start + 1
	count = 1
	while i <= end:
		if A[i] <= A[i-1]:
			count+=1
		else:
			if count%2==0:
				dec += (count/2)*(count-1)
			else:
				dec += count*((count-1)/2)
			count = 1
		i+=1

	if count != 1:
		if count%2==0:
			dec += (count/2)*(count-1)
		else:
			dec += count*((count-1)/2)	
	print inc-dec