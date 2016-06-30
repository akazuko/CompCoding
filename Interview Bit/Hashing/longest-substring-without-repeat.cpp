int Solution::lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> vis(256,-1);
    int ans = INT_MIN;
    int cur_len = 1;
    vis[(int)A[0]] = 0;
    for(int i = 1; i<A.size(); ++i){
        int last_visit = vis[(int)A[i]];
        if(last_visit == -1 || i - cur_len > last_visit) cur_len++;
        else{
            ans = max(ans, cur_len);
            cur_len = i - last_visit;
        }
        vis[(int) A[i]] = i;
    }
    ans = max(ans, cur_len);
    return ans;
}
