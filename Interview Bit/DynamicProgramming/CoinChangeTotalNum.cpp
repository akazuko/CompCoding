// Arithmetic 
int Solution::coinchange2(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int n = A.size();
    int ans[B+1];
    int k = 1000007;
    for(int i=0; i<=B; ++i) ans[i] = 0;
    ans[0]=1;
    for(int i=0; i<n; ++i)
        for(int j=A[i]; j<=B; ++j)
            ans[j] = (ans[j]%k +  ans[j-A[i]]%k)%k;
   
    return ans[B];
}
