int Solution::colorful(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int nod = 0;
    int temp = A;
    vector<int> dig;
    while(temp){
        dig.push_back(temp%10);
        temp = temp/10;
    }
    
    reverse(dig.begin(), dig.end());
    int k = dig.size();
    vector<int> cmul(k+1);
    cmul[0] = 1;
    map<int,int> exist;
    
    for(int i=0; i<k; ++i){
        exist[dig[i]] += 1;
        if(exist[dig[i]] > 1) return 0;
    }
    for(int i=1; i<=k; ++i){
        cmul[i] = cmul[i-1]*dig[i-1];
    }
    
    for(int size = 2; size <= k; ++size){
        for(int start = 1; start <= k-size+1; ++start){
            int mul_val = cmul[start+size-1]/cmul[start-1];
            exist[mul_val]+=1;
            if(exist[mul_val] > 1) return 0;
        }
    }
    return 1;
}
