class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def tp(self, A, B):
        s=0
        cnt=1
        for i in A:
            s=s+i
            if s>B:
                cnt+=1
                s=i
        return cnt
        
    def books(self, A, B):
        if B > len(A):
            return -1
        start = max(A)
        end = sum(A)
        while start<end:
            mid = start + (end-start)/2
            nos = self.tp(A,mid)
            if nos <= B:
                end = mid
            else:
                start=mid+1
        return start
                
            
            
            