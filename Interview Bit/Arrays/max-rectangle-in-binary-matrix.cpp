int calcArea(int h[], int n){
    // vector<int> h
    stack<int> s;
    int i = 0;
    // int n = h.size();
    int ans = 0;
    while(i<n){
        if(s.empty() || h[s.top()]<=h[i]) s.push(i++);
        else{
            int index = s.top();
            s.pop();
            ans = max(ans, h[index]*(s.empty()?i:i-s.top()-1));
        }
    }
    
    while(!s.empty()) {
        int index = s.top();
        s.pop();
        ans = max(ans, h[index] * (s.empty()?i:i - s.top() - 1));
    }
    return ans;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int row = A.size();
    int col = A[0].size();
    //vector<vector<int> > dp(row, vector<int>(col, 0));
    int dp[row][col];
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; ++j){
            if(A[i][j]==1){
                if(i==0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 1 + dp[i-1][j];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i<row; ++i){
        ans = max(ans, calcArea(dp[i], col));
        //cout<<i<<" "<<ans<<endl;
    }
    return ans;
}
