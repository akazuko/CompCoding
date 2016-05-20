# Enter your code here. Read input from STDIN. Print output to STDOUT
for T in range(int(raw_input())):
    N,M=map(int,raw_input().split())
    leftover=M%N
    left = 0
    right = 0
    
    times=M/N
    if leftover==0:
    	times-=1

    if N%2==0:

    	term_index=0
    	t1=times%2
    	t2=times/2

    	left=N/2
    	right=N/2
    		
    	if M%2==1:
    		if t1==1:
    			term_index=(t2+1)*(N/2)+(t2)*(N/2)
    		else:
    			term_index=(t2)*(N/2)+(t2)*(N/2)
    		first_term=2*term_index-1+2
    		pos=(M-first_term)/2+1
    		print pos,times
    	else:
    		if t1==1:
    			term_index=(t2+1)*(N/2)+(t2)*(N/2)
    		else:
    			term_index=(t2)*(N/2)+(t2)*(N/2)

    		first_term=2*term_index+2
    		pos=(M-first_term)/2+1
    		print N-pos+1,times
    else:
    	term_index=0
    	t1=times%2
    	t2=times/2
    	if t1==1:
    		left=N/2+1
    		right=N/2
    		 
    	else:
    		left=N/2
    		right=N/2+1
    		
    	if M%2==1:
    		if t1==1:
    			term_index=(t2+1)*(N/2+1)+(t2)*(N/2)
    		else:
    			term_index=(t2)*(N/2+1)+(t2)*(N/2)
    		first_term=2*term_index-1+2
    		pos=(M-first_term)/2+1
    		print pos,times
    	else:
    		if t1==1:
    			term_index=(t2+1)*(N/2)+(t2)*(N/2+1)
    		else:
    			term_index=(t2)*(N/2+1)+(t2)*(N/2)

    		first_term=2*term_index+2
    		pos=(M-first_term)/2+1
    		print N-pos+1,times