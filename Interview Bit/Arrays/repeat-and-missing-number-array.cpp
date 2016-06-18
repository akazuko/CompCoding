vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int x = 0;
    int y = 0;
    int n = A.size();
    int xor1 = A[0];
    int xor2 = 0;
    for(int i=1;i<n; ++i)
        xor1 ^= A[i];
    for(int i=1;i<=n; ++i)
        xor1 ^= i;
    int set_bit_no = xor1 & ~(xor1-1);
    
    for(int i = 0; i<n; ++i){
        if(A[i]&set_bit_no)
            x = x^A[i];
        else
            y = y^A[i];
    }
    
    for(int i = 1; i<=n; ++i){
        if(i&set_bit_no)
            x = x^i;
        else
            y = y^i;
    }
    
    vector<int> ans;
    int cnt = 0;
    for(int i : A)
        if(x==i)
            cnt++;
    if(cnt==2){
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
    ans.push_back(y);
    ans.push_back(x);
    return ans;


    /*
    Alternate solution : 

    long long sum = 0;
    long long sq_sum = 0;
    long long temp = 0;
    for(int i=0; i<n; ++i){
        sum += A[i];
        sum -= (i+1);

        temp = (long long)(A[i]*A[i]);
        sq_sum += (temp - (long long)((i+1)*(i+1)) );
    }
    int val  = sq_sum/sum;
    int b = (val - sum)/2;
    int a =  val - a;
    retrurn [a,b];
    */
}
