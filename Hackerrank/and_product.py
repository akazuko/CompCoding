'''
we progress from LSB 
with x=0 ans x=x<<1|1 we get x=00000000000,00000000001,00000000011,00000000111 and so on in binary form
masking m with x and then checking (m | x) < n allows us to identify the the very next bit at which value differs from
the right hand side in binary representation thus from there onwards all the bits would have the same value and all bits
to right hand side have 0 upon AND operation, hence answer is ( m AND (NOT x) ), making those last bits zeroes.
'''
def rang(m,n):
    x=0
    while((m|x) < n):
        x = (x<<1) | 1
    return m&~x

for T in range(int(raw_input())):
    A,B = map(int,raw_input().split())
    print rang(A,B) 