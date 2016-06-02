vector<int> Solution::equal(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<int, pair<int, int> > Hash;
    int n = A.size();
    //vector<int> ans; 
    vector<int> Ans;
    // Traverse through all possible pairs of arr[]
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = A[i] + A[j];
            if (Hash.find(sum) == Hash.end())
                Hash[sum] = make_pair(i, j);
 
            else {
                
                pair<int, int> pp = Hash[sum];
                vector<int> ans;
                if(pp.first==i || pp.second==j || pp.first==j || pp.second==i) continue;
                ans.push_back(pp.first);
                ans.push_back(pp.second);
                ans.push_back(i);
                ans.push_back(j);
                
                if (Ans.size() == 0) Ans = ans;
                else {
                    bool shouldReplace = false;
                    for (int i1 = 0; i1 < Ans.size(); i1++) {
                        if (Ans[i1] < ans[i1]) break;
                        if (Ans[i1] > ans[i1]) {
                            shouldReplace = true;
                            break;
                        }
                    }
                    if (shouldReplace) Ans = ans;
                }
            }
        }
    }
    return Ans;
}
