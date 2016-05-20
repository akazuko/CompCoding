class Solution:
    # @param A : integer
    # @return an integer
    def reverse(self, A):
        if A<0:
            k='-' + str(abs(A))[::-1]
        else:
            k = str(A)[::-1]
        p=int(k)
        if p>2147483647:
            return 0
        if p<-2147483648:
            return 0
        return p