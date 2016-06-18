int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n =A.size();
    if(n==0) return -1;
    if(n==1) return 0;
    vector<int> lmin(n);
    vector<int> rmax(n);
    lmin[0] = A[0];
    for(int i=1; i<n; ++i)
        lmin[i] = min(lmin[i-1], A[i]);
    rmax[n-1] = A[n-1];
    for(int i=n-2; i>=0; --i)
        rmax[i] = max(rmax[i+1], A[i]);
    int i = 0;
    int j = 0;
    int ans = -1;
    while(i<n && j<n){
        if(lmin[i]<=rmax[j]){
            ans = max(ans, j-i);
            j++;
        }
        else
            i++;
    }
    return ans;
    
}   
