# Enter your code here. Read input from STDIN. Print output to STDOUT
# Let's try to optimize our previous solution. 
# Let res be our decoded message (like "abcd..." in example above). 
# Let's solve easier challenge, where res is written not K times, but infinite number times and we get onl first N letters as encoded message.
# i:  012.....
# S:  ABCDEFGH...  =
# res:abcdefg...  ^
# res: abcdefg...  ^
# ...   abcdefg...  ^
#        abcdefg...  ^
#         abcdefg...  ^
#          abcdefg...  ^
#           ...
# Here if a in "abcd..." is 1 we can inverse all values in "BCD..." and solve challenge for "BDC..." and "bcd...". 
# If a is 0 we don't inverse values and continue solving smaller challenge for "BDC..." and "bcd..." too. 
# So we can create some bool variable x which will be true if we need to reverse values in S[i]..S[N] and false vice versa. 
# Now we can write that res[i] = S[i]^x, x^=res[i]. 
# Solved.
N, K = map(int, raw_input().split())
S = raw_input()
res=''
x=0
for i in range(N):
    if i>=K:
        x^=int(res[i-K])
    temp=int(S[i])^x
    res+=str(temp)
    x^=temp
print res