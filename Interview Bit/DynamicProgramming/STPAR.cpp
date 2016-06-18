int Solution::canJump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    vector<bool> vis(n,false);
    vis[0] = true;
    for(int i= 0; i<n; ++i){
        if(vis[i]){
            for(int j = i+1; j<=min(n-1,i+A[i]); ++j)
                vis[j] = true;
        }
    }
    if(vis[n-1])
        return 1;
    return 0;
}
