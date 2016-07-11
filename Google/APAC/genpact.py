# l = range(200000)
f = open('testD.txt','w')
f.write('10\n')
ans = ""
for i in range(200000):
	ans += str(i) + " "
for test in range(10):
	f.write("200000 20\n")
	f.write(ans + '\n')
	l = "1 15\n"
	for i in range(20):
		f.write(l)
f.close()