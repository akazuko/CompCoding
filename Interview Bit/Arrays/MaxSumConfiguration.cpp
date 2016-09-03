/*You are required to complete this method*/
int max_sum(int A[],int N) {
    int sum = 0;
    int ans = INT_MIN;
    int v1 = 0;
    for(int i = 0; i<N; ++i) sum+=A[i];
    for(int i = 0; i<N; ++i) v1 += A[i]*i;
    ans = v1;
    int v2;
    for(int i = 1; i<N; ++i){
        v2 = v1 - sum + A[i-1] + A[i-1]*(N-1);
        ans = max(ans, v2);
        v1 = v2;
    }
    return ans;
}
