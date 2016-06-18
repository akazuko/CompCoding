int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int start = 0;
    int gas_left = gas[start];
    int n = gas.size();
    int min_index = -1;
    int min_gas = INT_MAX;
    for(int i = 1; i<=n; ++i){
        gas_left  = gas_left - cost[(start + i - 1)%n];
        if(gas_left < min_gas){
            min_gas = gas_left;
            min_index = (start + i)%n;
        }
        gas_left += gas[(start + i)%n];
    }
    
    if(min_gas >=0 ) return 0;
    
    start = min_index;
    gas_left = gas[start];
    for(int i = 1; i<=n; ++i){
        gas_left  = gas_left - cost[(start + i - 1)%n];
        if(gas_left < 0)
            return -1; 
        gas_left += gas[(start + i)%n];
    }
    
    return min_index;
}
