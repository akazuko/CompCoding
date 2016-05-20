class Solution:
    # @param A : tuple of integers
    # @param B : tuple of integers
    # @param C : tuple of integers
    # @return an integer
    def minimize(self, A, B, C):
        i=0
        j=0
        k=0
        n1=len(A)
        n2=len(B)
        n3=len(C)
        diff=10000000000000000000
        while(i < n1 and j<n2 and k<n3):
            a=min(A[i], B[j], C[k])
            b=max(A[i], B[j], C[k])
            diff=min(abs(a-b), diff)
            if a==B[j]:
                j+=1
            elif a==C[k]:
                k+=1
            elif a==A[i]:
                i+=1
            if diff == 0:
                break
        return diff