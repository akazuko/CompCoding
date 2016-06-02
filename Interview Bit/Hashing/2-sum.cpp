vector<int> Solution::twoSum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int t;
    vector<int> ans;
    int n = A.size();
    map<int, int> ex;
    for(int i = 1; i<=n ; ++i){
        t = B-A[i-1];
        if(ex.find(t)!=ex.end()){
            ans.push_back(ex[t]);
            ans.push_back(i);
            return ans;
        }
        else{
            if(ex[A[i-1]]==0)
                ex[A[i-1]] = i;
        }
    }
    return ans;
}