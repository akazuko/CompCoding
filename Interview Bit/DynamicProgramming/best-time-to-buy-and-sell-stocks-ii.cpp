int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int ans = 0;
    int i= 0;
    int n = A.size();
    while(i<n-1){
        while(i<n-1 && A[i+1]<=A[i]) i++;
        if(i==n-1) break;
        int temp1 = A[i];
        i++;
        while(i<n && A[i]>=A[i-1]) i++;
        ans += A[i-1] - temp1;
    }
    return ans;
}
