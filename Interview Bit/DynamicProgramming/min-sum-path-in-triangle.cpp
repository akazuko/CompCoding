int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int ans = INT_MAX;
    int n = A.size() - 1;
    int dp[2][A.size()];
    dp[0][0] = A[0][0];
    for(int i = 1; i<A.size(); ++i){
        for(int j = 0; j<=i; ++j){
            dp[i%2][j] = INT_MAX;
            if(j-1>=0 && j-1<i)  dp[i%2][j] = min(dp[i%2][j], A[i][j] + dp[1-i%2][j-1] );
            if(j>=0 && j<i)      dp[i%2][j] = min(dp[i%2][j], A[i][j] + dp[1-i%2][j]   );
        }
    }
    for(int i = 0; i<=n; ++i)
        ans = min(ans, dp[n%2][i]);
    return ans;
}
