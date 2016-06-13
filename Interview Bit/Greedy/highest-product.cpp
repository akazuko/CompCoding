int cmp(int a, int b){
    return a>b;
}
int Solution::maxp3(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    if(n<3) return -1;
    
    sort(A.begin(), A.end(), cmp);
    return max(A[0]*A[1]*A[2], A[n-1]*A[n-2]*A[0]);
}