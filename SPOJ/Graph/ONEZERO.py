r=raw_input
from Queue import Queue

def bfs(n):
	q = Queue()
	q.put(1)
	while not q.empty():
		val = q.get()
		# print val
		if val%n==0:
			return val
		q.put(val*10 + 0)
		q.put(val*10 + 1)
	pass

for t in range(int(r())):
	n = int(r())
	print bfs(n)