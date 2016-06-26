int fact(int n){
    if(n>12)
        return INT_MAX;
    int ans = 1;
    for(int i=2; i<=n; ++i)
        ans*=i;
    return ans;
}
string Solution::getPermutation(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string ans;
    if(n==0) return "";
    vector<int> m;
    for(int i=1; i<=n; ++i) m.push_back(i);
    k--;
    while(n>0){
        int fval =fact(n-1);

        if(k > fact(n)){
            break;
        }
        int pos = k/fval;
        ans+=to_string(m[pos]);
        m.erase(m.begin() + pos);
        k %= fval;
        
        n--;
    }
    return ans;
     
}
