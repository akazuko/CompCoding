/*You are required to complete this function*/
int maxLen(int A[],int n)
{
    int ans = 0;
    map<int, int> m;
    m[0] = -1;
    int sum = 0;
    for(int i = 0; i<n;++i){
        sum+= A[i];
        if(m.find(sum)!=m.end()){
            ans = max(ans, i - m[sum]);
        }
        else m[sum] = i;
    }
    return ans;
}
