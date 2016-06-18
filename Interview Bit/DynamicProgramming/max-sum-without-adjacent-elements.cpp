int Solution::adjacent(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A[0].size();
    int dp[2][n];
    
    if(n==1)
        return max(A[0][0], A[1][0]);
    
    dp[0][0] = A[0][0];
    dp[1][0] = A[1][0];
    dp[0][1] = A[0][1];
    dp[1][1] = A[1][1];
    
    int ans = max(max(dp[0][0],dp[1][0]), max(dp[0][1], dp[1][1]));
    
    for(int i=2; i<n; ++i){
        dp[0][i] = A[0][i] + max(dp[0][i-2], dp[1][i-2]);
        dp[1][i] = A[1][i] + max(dp[0][i-2], dp[1][i-2]);
        if(i-3>=0){
            dp[0][i] = max(dp[0][i], A[0][i] + max(dp[0][i-3], dp[1][i-3]));
            dp[1][i] = max(dp[1][i], A[1][i] + max(dp[0][i-3], dp[1][i-3]));
        }
        ans = max(ans, max(dp[0][i], dp[1][i]));
    }
    return ans;
}
