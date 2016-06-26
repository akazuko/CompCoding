void genP(map<vector<int>, int> &ans, vector<int> cur, int sum, int target, vector<int> A, int index){
    //cout<<"sum "<<sum<<endl;
    if(sum > target)
        return;
    if(target==sum){
        if(ans[cur]!=1)
            ans[cur] = 1;
    }
    else{
        for(int i=index; i<A.size(); ++i){
            cur.push_back(A[i]);
            genP(ans, cur, sum + A[i], target, A, i);
            cur.pop_back();
        }
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    sort(A.begin(), A.end());
    map<vector<int>, int> ans;
    vector<int> cur;
    genP(ans, cur, 0, B, A, 0);
    vector< vector<int> > res;
    for(auto i : ans)
        res.push_back(i.first);
    return res;
}

