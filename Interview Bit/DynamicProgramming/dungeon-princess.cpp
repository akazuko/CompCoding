int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int m = A.size();
    int n = A[0].size();
    int dp[m][n];
    int k = 1;
    for(int i = m-1; i>=0; --i){
        for(int j = n-1; j>=0; --j){
            if(i==m-1 && j==n-1) dp[i][j] = max(1 - A[i][j], 1);
            else if(i==m-1)      dp[i][j] = max(dp[i][j+1]  - A[i][j], 1);
            else if(j==n-1)      dp[i][j] = max(dp[i+1][j]  - A[i][j], 1);
            else dp[i][j] = min( max(dp[i][j+1]  - A[i][j], 1) , max(dp[i+1][j]  - A[i][j], 1) );
        }
    }
    return dp[0][0];
}
