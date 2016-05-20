# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import defaultdict

s=raw_input()
l=defaultdict(int)
for k in s:
    if k != ' ':
        l[k.lower()]+=1
if len(l.keys()) == 26 :
    print 'pangram'
else:
    print 'not pangram'