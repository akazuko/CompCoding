void gensets(int cur, vector<vector<int> > &ans, vector<int> temp, vector<int> A){
    //if(cur==A.size()) return;
    ans.push_back(temp);
    for(int i = cur; i<A.size(); ++i){
        temp.push_back(A[i]);
        gensets(i+1, ans, temp, A);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end());
    vector<vector<int> > ans;
    vector<int> temp;
    gensets(0, ans, temp, A);
    return ans;
}
