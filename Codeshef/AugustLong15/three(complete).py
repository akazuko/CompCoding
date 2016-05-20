fibs=[1,1]
for i in range(2,94):
	fibs.append(fibs[-1]+fibs[-2])


for T in range(int(raw_input())):
	N=int(raw_input())
	for i in range(1,94):
		if N<fibs[i]:
			print i-1
			break