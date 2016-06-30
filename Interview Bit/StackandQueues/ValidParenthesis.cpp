int Solution::isValid(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    stack<int> s;
    for(int i=0; i<A.size(); ++i){
        if(A[i]=='(' || A[i]=='{' || A[i]=='[') s.push(A[i]);
        else if (A[i]==')' && !s.empty() && s.top()=='(' ) s.pop();
        else if (A[i]=='}' && !s.empty() && s.top()=='{' ) s.pop();
        else if (A[i]==']' && !s.empty() && s.top()=='[' ) s.pop();
        else if (A[i]==')' && (s.empty() || s.top()!='(' )) return 0;
        else if (A[i]=='}' && (s.empty() || s.top()!='{' )) return 0;
        else if (A[i]==']' && (s.empty() || s.top()!='[' )) return 0;
    }
    if(!s.empty())
        return 0;
    return 1;
}
