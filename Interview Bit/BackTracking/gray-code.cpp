vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> ans;
    ans.push_back(0);
    ans.push_back(1);
    
    int cur = 2;
    
    while(cur<=A){
        vector<int> temp = ans;
        int val = pow(2,cur-1);
        for(int i = ans.size()-1; i>=0; --i){
            temp.push_back(ans[i] + val);
        }
        ans = temp;
        cur++;
    }
    
    return ans;
}
