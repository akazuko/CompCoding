int Solution::jump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int jumps = 0;
    if(n < 2){
        return jumps;
    }
    int cur = 0; // current index,
    int cur_step;// number of step you can jump in current index 
    int last;    // last index
    int temp_max = cur; // temporary max jump distance 
    int temp_index = cur;// temporary index.

    while(cur < n){
        last = cur;
        cur_step = A[cur];
        if((cur + cur_step) >= n-1){ // if reached end of the array, return.
            jumps++;
            return jumps;
        }
        for(int ii = cur + 1; ii <= cur + cur_step; ii++){//go thru all the possible next position, and find the one that could jump most steps.
            if(A[ii] == 0){
                continue;
            }
            if(A[ii] + ii > temp_max){ // find the one that could jump most steps.
                temp_index = ii;
                temp_max = A[ii] + ii;
            }
        }
        cur = temp_index; // jump to this position, temp index holds index that jump most steps in next jump.
        if(cur != last){
            jumps++;
        }else{
            break;
        }
    }
    return -1;
}
