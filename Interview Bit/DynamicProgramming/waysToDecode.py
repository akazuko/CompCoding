class Solution:
    # @param A : string
    # @return an integer
    def numDecodings(self, A):
        n=len(A)
        if n==1:
            if A=='0':
                return 0
            return 1
        if A[0]=='0':
            return 0
        dp=[0]*(n+1)
        dp[0]=1
        dp[1]=1
        for i in range(2,n+1):
            if A[i-1]=='0':
                if A[i-1-1]>'2':
                    return 0
            if A[i-1]!='0':
                dp[i]+=dp[i-1]
            num = int(A[i-1-1] + A[i-1])
            if num<=26 and A[i-2]!='0':
                dp[i]+=dp[i-2]
        return dp[n]