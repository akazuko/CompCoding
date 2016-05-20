class Solution:
    def arrange(self, A, B):
        n=len(A)
        now = [0]*n
        nob = [0]*n
        for i in range(n):
            if i==0:
                if A[i]=='W':
                    now[i]+=1
                elif A[i]=='B':
                    nob[i]+=1
            else:
                if A[i]=='W':
                    now[i]=now[i-1] + 1
                    nob[i] = nob[i-1]
                elif A[i]=='B':
                    now[i] = now[i-1]
                    nob[i]=nob[i-1] + 1
        dp = [[float('inf') for y_ in range(B+1) ] for x_ in range(n+1) ]
        for i in range(1,n+1):
            for j in range(1,min(i+1,B+1)):
                if j==1:
                    dp[i][j]=now[i-1]*nob[i-1]
                else:
                    for p in range(i-1,0,-1):
                        dp[i][j] = min(dp[p][j-1] + (now[i-1]-now[p-1])*(nob[i-1]-nob[p-1]), dp[i][j])
        return dp[n][B]
# s=Solution()
# print s.arrange("BWWWWBBWWBWBWWBBBBBWBWWBBBWWWWBBBW",28)