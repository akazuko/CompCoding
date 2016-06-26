int Solution::maxcoin(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    vector<int> csum(n, 0);
    csum[0] = A[0];
    
    int dp[n][n];
    for(int game_size=0; game_size<n; game_size++){
        for(int i = 0, j = game_size; j<n ; ++j, ++i){
            int a = (i+2<=j?dp[i+2][j] : 0);
            int b = (i+1<=j-1 && j-1>=0?dp[i+1][j-1] : 0);
            int c = (i<=j-2?dp[i][j-2] : 0);
            dp[i][j] = max(A[i] + min(a,b), A[j] + min(b,c));
        }
    }
    return dp[0][n-1];
}
