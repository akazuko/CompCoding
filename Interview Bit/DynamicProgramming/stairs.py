class Solution:
    # @param A : integer
    # @return an integer
    def climbStairs(self, A):
        if A==1:
            return 1
        if A==2:
            return 2
        dp=[0]*(A+1)
        dp[1] = 1
        dp[2] = 2
        for i in range(3,A+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[A]
