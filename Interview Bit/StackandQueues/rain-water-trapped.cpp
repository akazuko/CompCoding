int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    vector<int> l(n);
    vector<int> r(n);
    l[0] = A[0];
    for(int i = 1; i<n; ++i) l[i] = max(l[i-1], A[i]);
    r[n-1] = A[n-1];
    for(int i = n-2; i>=0; --i) r[i] = max(r[i+1], A[i]);
    int ans = 0;
    for(int i = 0; i<n; ++i) ans += min(l[i], r[i]) - A[i];
    return ans;
}
