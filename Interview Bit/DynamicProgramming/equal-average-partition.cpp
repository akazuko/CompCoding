vector<vector<vector<bool> > > dp;
vector<int> res;
vector<int> real;
int total;
 
bool isPossible(int idx, int sum, int len)
{
    if (len == 0) return (sum == 0);
    if (idx >= total) return false;
 
    if (dp[idx][sum][len] == false) return false;
 
    if (sum >= real[idx])
    {
        res.push_back(real[idx]);
        if (isPossible(idx + 1, sum - real[idx], len - 1)) return true;
        res.pop_back();
    }
     
    if (isPossible(idx + 1, sum, len)) return true;
 
    return dp[idx][sum][len] = false;
}

vector<vector<int> > Solution::avgset(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    real.clear();
    real = arr;
    dp.clear();
    res.clear();
 
    int total_sum = 0;
    total = arr.size();
 
    for(int i = 0; i < total; ++i)
        total_sum += arr[i];
     
    dp.resize(real.size(), vector<vector<bool> > (total_sum + 1, vector<bool> (total, true)));
 
    // We need to minimize size_of_set1. So, lets search for the first size_of_set1 which is isPossible. 
    for (int i = 1; i < total; i++)
    {
        // Sum_of_Set1 has to be an integer
        if ((total_sum * i) % total != 0) continue;
        int Sum_of_Set1 = (total_sum * i) / total;
        if (isPossible(0, Sum_of_Set1, i))
        {
            // Ok. Lets find out the elements in arr, not in res, and return the result.
            int ptr1 = 0, ptr2 = 0;
            vector<int> res1 = res;
            vector<int> res2;
            while (ptr1 < arr.size() || ptr2 < res.size())
            {
                if (ptr2 < res.size() && res[ptr2] == arr[ptr1])
                {
                    ptr1++;
                    ptr2++;
                    continue;
                }
                res2.push_back(arr[ptr1]);
                ptr1++;
            }
 
            vector<vector<int> > ans;
            ans.push_back(res1);
            ans.push_back(res2);
            return ans;
        }
    }
 
    vector<vector<int> > ans;
    return ans;
}
