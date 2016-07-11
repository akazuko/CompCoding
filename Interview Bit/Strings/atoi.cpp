int Solution::atoi(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int ans = 0;
    int i = 0;
    while(i < A.size() && A[i]==' ') i++;
    bool neg = false;
    if(i >= A.size()){
        return ans;
    }
    
    if(A[i]=='-'){
        neg = true;
        i++;
    }
    else if(A[i] == '+'){
        neg = false;
        i++;
    }
    while(i < A.size()){
        int kk = A[i] - '0';
        if(kk >=0 && kk <=9){
            if     (!neg &&  ans >  INT_MAX/10)          return INT_MAX;
            else if(!neg &&  ans == INT_MAX/10 && kk>=7) return INT_MAX;
            else if( neg && -ans <  INT_MIN/10)          return INT_MIN;
            else if( neg && -ans == INT_MIN/10 && kk>=8) return INT_MIN;
            ans = ans*10 + kk;
        }
        else
            break;
        i++;
    }
    if(neg)
        ans*=-1;
    return ans;
}
