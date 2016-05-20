'''
The property used here is : a^(a^b) = b
This alloes to test (after pen paper checking :P ) that
if N is even 
then 
    all such reductions would come in pairs and as we know
    a^a = 0 thus answer = 0
else:
    again by pen paper testing all numbers at even position would eventually be left to be xored
    So do that
    and then print answer

Why s=0 is taken iniatially?
Becz 0^a = a

'''
# Enter your code here. Read input from STDIN. Print output to STDOUT
for T in range(int(raw_input())):
    N=int(raw_input())
    l=map(int,raw_input().split())
    s = 0
    if N%2==0:
        print 0
    else:
        m=0
        while m < N:
            s=s^l[m]
            m+=2
        print s