int comp(string a, string b){
    string AB = a.append(b);
    string BA = b.append(a);
    return AB > BA;
}
 
string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> B;
    for(int i:A) B.push_back(to_string(i));
    sort(B.begin(), B.end(), comp);
    string ans;
    for(string a : B) ans+=a;
    if(ans.size()>0 && ans[0]=='0') return "0";
    return ans;
}