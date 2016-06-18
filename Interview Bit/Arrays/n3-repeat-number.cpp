int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int num1, num2, cnt1, cnt2;
    num1=num2=INT_MIN;
    cnt1=cnt2=0;
    if(A.size()==0) return -1;
    if(A.size()==1) return A[0];
    int k = A.size()/3;
    
    for(int i  : A){
        if(num1==i){
            cnt1++;
        }
        else if(num2==i){
            cnt2++;
        }
        else if(cnt1==0){
            cnt1 = 1;
            num1 = i;
        }
        else if(cnt2==0){
            num2 = i;
            cnt2 = 1;
        }
        
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=cnt2=0;
    
    for(int i : A){
        if(i==num1)
            cnt1++;
        else if(i==num2)
            cnt2++;
    }
    
    if(cnt1 > k)
        return num1;
    if(cnt2 > k)
        return num2;
    return -1;
}
