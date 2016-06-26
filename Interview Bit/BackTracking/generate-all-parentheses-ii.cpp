void genP(vector<string> &ans, int open, int close, int n, string cur){
    if(open==n && close==n){
        ans.push_back(cur);
    }
    else if(open==n){
        genP(ans, open, close + 1, n, cur + ")");
    }
    else if(open < n){
        if(open==close){
            genP(ans, open + 1, close, n, cur + "(");
        }
        else if(open > close){
            genP(ans, open, close + 1, n, cur + ")");
            genP(ans, open + 1 , close, n, cur + "(");
        }
    }
}
vector<string> Solution::generateParenthesis(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<string> ans;
    genP(ans, 0, 0, A, "");
    vector<string> ans2;
    for(int i=ans.size()-1; i>=0; --i)
        ans2.push_back(ans[i]);
    return ans2;
}
