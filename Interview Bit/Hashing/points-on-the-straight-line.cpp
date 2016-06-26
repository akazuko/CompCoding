int gcd(int a, int b) {
            if (a == 0) return b;
            if (b == 0) return a;
            if (a < 0) return gcd(-1 * a, b);
            if (b < 0) return gcd(a, -1 * b);
            if (a > b) return gcd(b, a);
            return gcd(b%a, a);
    }
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<pair<int,int>, int> slope;
    if(A.size()==1)
        return 1;
    int ans = 0;
    for(int i=0; i<A.size(); ++i){
        slope.clear();
        int same_value = 1;
        int cur_max = 0;
        for(int j=i+1; j<A.size(); ++j){
            int xdif = A[i] - A[j];
            int ydif = B[i] - B[j];
            if(xdif==0 && ydif==0){
                same_value++;
                continue;
                
            }
            if(xdif<0){
                xdif *= -1;
                ydif *= -1;
            }
            int gcd_val = gcd(xdif, ydif);
            slope[make_pair(xdif/gcd_val, ydif/gcd_val)]++;
            cur_max = max(cur_max, slope[make_pair(xdif/gcd_val, ydif/gcd_val)]);
        }
        cur_max += same_value;
        ans = max(ans, cur_max);
    }
    return ans;
}
