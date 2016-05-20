from math import factorial
class Solution:
    # @param A : string
    # @return an integer
    def findRank(self, A):
        n=len(A)-1
        l = list(A)
        l.sort()
        val = 0
        for i in A:
            val += l.index(i)*factorial(n)
            #print l,l.index(i),val
            l.remove(i)
            n-=1
        return (val+1)%1000003