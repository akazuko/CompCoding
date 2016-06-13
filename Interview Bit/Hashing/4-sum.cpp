vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<int, vector< pair<int,int> > > m;
    int t;
    sort(A.begin(), A.end());
    vector< vector<int> > ans;
    set<vector<int> > aaa;
    //map<vector<int> , bool> ans;
    for(int i=0; i<A.size(); ++i)
        for(int j=i+1; j<A.size(); ++j)
            m[A[i]+A[j]].push_back(make_pair(i,j));
    while(m.size()){
        auto it = m.begin();
        if(m.find(B - it->first)!=m.end()){
            for(auto i : m[it->first]){
                for(auto j : m[B-it->first]){
                    if(i.first!=j.first && i.second!=j.first && i.first!=j.second && i.second!=j.second){
                        vector<int> ll;
                        ll.push_back(A[i.first]);
                        ll.push_back(A[i.second]);
                        ll.push_back(A[j.first]);
                        ll.push_back(A[j.second]);
                        sort(ll.begin(), ll.end());
                        aaa.insert(ll);    
                    }
                }
            }
        }
        m.erase(it);
    }
    for(auto i : aaa)
        ans.push_back(i);
    return ans;
}
