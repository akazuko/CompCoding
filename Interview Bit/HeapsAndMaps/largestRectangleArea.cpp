int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0;
    stack<int> s;
    int n = A.size();
    int ans = INT_MIN;
    while( i < n ){
        if(s.empty() || A[s.top()] <= A[i]) s.push(i);
        else{
            int index = s.top();
            s.pop();
            ans = max(ans, A[index]*(s.empty()?i: i - s.top() - 1));
        }
    }
    while(!s.empty()){
        int index = s.top();
        s.pop();
        ans = max(ans, A[index]*(s.empty()?i: i - s.top() - 1));
    }
    return ans;
}