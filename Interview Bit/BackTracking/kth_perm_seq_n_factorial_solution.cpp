void genP(string &ans, int &cur_k, int k, string cur, vector<bool> &vis, int n, int visN, bool &done){
    
    if(done)
        return;
    if(visN==n){
        cur_k +=1;
        ans = cur;
    }
    if(cur_k==k)
        done = true;

    for(int i=1; i<=n && cur_k!=k; ++i){
        if(!vis[i]){
            vis[i] = true;
            genP(ans, cur_k, k, cur + to_string(i), vis, n, visN + 1, done);
            vis[i] = false;
        }
    }
}
string Solution::getPermutation(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    string ans;
    int cur_k = 0;
    vector<bool> vis(n+1, false);
    bool done = false;
    genP(ans, cur_k, k, "", vis, n, 0, done);
    return ans;
}
