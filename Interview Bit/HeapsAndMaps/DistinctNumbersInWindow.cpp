vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    
    vector<int> ans;
    if(B>n) return ans;
    
    map<int,int> m;
    for(int i=0; i<B; ++i)
        m[A[i]]+=1;
    ans.push_back(m.size());
    
    for(int i=B; i<n; ++i){
            m[A[i]]+=1;
            m[A[i-B]]-=1;
            if(m[A[i-B]]==0) m.erase(A[i-B]);
            ans.push_back(m.size());
    }
    return ans;
}
