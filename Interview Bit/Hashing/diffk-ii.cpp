int Solution::diffPossible(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<int,int> m;
    for(int i : A){
        int val = B + i;
        if(m[val]==1)
            return 1;
        m[i] = 1;
    }
    m.clear();
    for(int i : A){
        int val = -1*(B - i);
        if(m[val]==1)
            return 1;
        m[i] = 1;
    }
    
    return 0;
}
