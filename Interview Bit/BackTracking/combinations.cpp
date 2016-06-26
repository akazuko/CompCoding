void genP(vector<vector<int> > &ans, int pos, vector<int> cur, int n, int k, int left){
    if(cur.size() == k){
        ans.push_back(cur);
        return;
    }
    for(int i = pos; i<=n; ++i){
        cur.push_back(i);
        genP(ans, i+1, cur, n, k, left - 1);
        cur.pop_back();
    }
}
vector<vector<int> > Solution::combine(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > ans;
    vector<int> cur;
    genP(ans, 1, cur, n, k, n);
    return ans;
}
