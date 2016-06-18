int Solution::minDistance(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.length();
    int m = B.length();
    int dp[n+1][m+1];
    
    for(int i=0; i<=n ; ++i){
        for(int j=0; j<=m; ++j){
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(A[i-1]==B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(  dp[i-1][j] // deletion of the ith element
                                    , min(dp[i][j-1], // insert operation as now (i+1)th and (j)th are same 
                                            dp[i-1][j-1]) );
        }
    }
    return dp[n][m];
}
