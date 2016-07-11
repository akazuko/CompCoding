int Solution::isMatch(const string &s, const string &p) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = s.size();
    int m = p.size();
    bool dp[n+1][m+1];
    for(int i = 0; i<=n; ++i){
        for(int j = 0; j<=m; ++j){
            if(i==0 && j==0) dp[i][j] = true;
            else if(j==0)         dp[i][j] = false;
            else if(i==0)         dp[i][j] = p[j-1] == '*' ? dp[i][j-2] : false;
            else{
                if(p[j-1]!='*'){
                    if(s[i-1]==p[j-1] || p[j-1]=='.')
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = false;
                }
                else{
                    if(s[i-1]!=p[j-2] && p[j-2]!='.')
                        dp[i][j] = dp[i][j-2];
                    else
                        dp[i][j] = dp[i][j-2] || dp[i-1][j] || dp[i][j-1];
                }
            }
        }
    }
    return dp[n][m] ? 1 : 0;
}
