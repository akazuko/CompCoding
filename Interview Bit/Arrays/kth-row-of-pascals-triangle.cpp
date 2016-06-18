vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int val[2][A+1];
    
    vector<int> ans;
    
    val[0][0] = 1;
    
    int k = 1;
    while(k<=A){
        for(int i=0; i<=k; ++i){
            if(i==0 || i==k)
                val[k%2][i] = 1;
            else
                val[k%2][i] = val[1-k%2][i] + val[1-k%2][i-1];
        }
        k++;
    }
    for(int i=0; i<=A; ++i)
        ans.push_back(val[A%2][i]);
    return ans;
}
