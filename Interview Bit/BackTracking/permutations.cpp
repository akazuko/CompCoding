void genP(vector<vector<int> > &ans, vector<bool> &vis, vector<int> cur, vector<int> A){
    if(cur.size()==A.size()){
        ans.push_back(cur);
        return;
    }
    for(int i = 0; i<A.size(); ++i){
        if(!vis[i]){
            vis[i] = true;
            cur.push_back(A[i]);
            genP(ans, vis, cur, A);
            cur.pop_back();
            vis[i] = false;
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > ans;
    vector<bool> vis(A.size(), false);
    vector<int> cur;
    genP(ans, vis, cur, A);
    return ans;
    
}
