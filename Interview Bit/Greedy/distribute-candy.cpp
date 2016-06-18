int Solution::candy(vector<int> &ratings) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = ratings.size();
    
    vector<int> candy(n,1);
    
    for(int i=0; i<n; ++i){
        if(i-1>=0 && ratings[i]>ratings[i-1])
            candy[i] = candy[i-1] + 1;
        else if(i+1 <n && ratings[i]>ratings[i+1])
            candy[i] = candy[i+1] + 1;
    
        int j = i-1;
        while(j>=0 && ratings[j] > ratings[j+1] && candy[j]<=candy[j+1]){
            candy[j] = candy[j+1] + 1;
            j--;
        }
    }
    
    int ans = 0;
    for(auto i : candy)
        ans += i;
    return ans;
}
