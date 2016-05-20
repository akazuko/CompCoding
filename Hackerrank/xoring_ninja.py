'''
Explaination : 
Solution: Find OR of all the elements and multiply it with 2^(n-1) where n is the total number of elements. This gives us the answer.
Idea:
There will be total 2^n subsets.
If ith bit of any element is set, then that bit will be set in xor of half of the total subsets which is 2^(n-1).
To find out all the set bits in all the numbers we find OR of all the numbers.
Since each set bit appears in half of the total subsets we multiply OR of all numbers with 2^n-1 to get the final result.
'''
for i in range(int(raw_input())):
    N =int(raw_input())
    l = map(long,raw_input().split())
    s = 0
    pin = 2**(N-1)
    for p in l:
        s = s|p
    print (s*pin)%1000000007