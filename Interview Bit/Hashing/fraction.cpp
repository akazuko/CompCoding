string Solution::fractionToDecimal(int numerator, int denominator) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    long long n = (long long )numerator;
    long long d = (long long )denominator;
    string res;
    if(n==0) return "0";
    
    if(!((n<0 && d<0) || (n>0 && d>0)))
        res+="-";

    n = abs(n);
    d = abs(d);
    
    res+= to_string((n / d));
    
    if(n%d==0) return res;
    res+=".";
    map<int,int> exists;
    
    for(long long r = n%d; r; r%=d){
        if(exists.find(r)!=exists.end()){
            res.insert(exists[r], 1, '(');
            res+=')';
            break;
        }
        exists[r] = res.size();
        r = r * 10;
        res.push_back((char)'0'+ (r/d));
    }
    return res;
}
