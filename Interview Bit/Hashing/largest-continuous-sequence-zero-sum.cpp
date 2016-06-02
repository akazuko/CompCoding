vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size();
    vector<int> csum(n+1);
    map<int, int> ref;
    csum[0] = 0;
    int maxx = INT_MIN;
    int start = -1;
    int end = -1;
    for(int i=1; i<=n; ++i) csum[i] = csum[i-1] + A[i-1];
    for(int i=0; i<=n; ++i){
        if(ref.find(csum[i])==ref.end()) ref[csum[i]] = i;
        else{
            if(maxx < (i - ref[csum[i]])){
               maxx =  i - ref[csum[i]];
               start = ref[csum[i]] + 1;
               end = i;
            }
        }
    }
    vector<int> ans;
    if(maxx == INT_MIN) return ans;
    
    for(int i = start; i<=end; ++i) ans.push_back(A[i-1]);
    return ans;
}
