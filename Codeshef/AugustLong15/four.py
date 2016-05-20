for T in range(int(raw_input())):
	N,H=map(int,raw_input().split())
	start=0
	end=N-1
	dig=0
	for k in range(N):
		x,y=map(int,raw_input().split())

		if end>y and start<x:
			l=y-x+1
			if k==0 and l>=H:
				start=x
				end=y
			if l<H:
				left=H-l
				if x-left>=0:
					dig+=left
					start=x-left
				elif y+left<N:
					dig+=left
					end=y+left
			# print start,end,dig
		elif end>y and start>x:
			l=y-start+1
			if l<H:
				dig+=H-l
				end=y+H-l
		elif end<y and start<x:
			l=end-x+1
			if l<H:
				dig+=H-l
				start=x-H+l

	print dig