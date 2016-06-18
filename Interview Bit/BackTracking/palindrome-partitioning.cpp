bool ispal(string s, int start, int end){
    while(start<=end){
        if(s[start]!=s[end])
            return false;
    start++;
    end--;
    }
    return true;
}

void partitionUtil(vector< vector<string> > &ans, vector<string> &cur, int now, int n, string A){
    if(now>=n){
        ans.push_back(cur);
        return;
    }
    
    for(int start = now; start<n; ++start){
        if(ispal(A, now, start)){
            cur.push_back(A.substr(now, start-now+1));
            partitionUtil(ans, cur, start+1, n, A);
            cur.pop_back();
        }
    }
    
    return;
}
vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector< vector<string> > ans;
    vector<string> cur;
    partitionUtil(ans, cur, 0, A.size(), A);
    return ans;
}
