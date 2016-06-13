int Solution::bulbs(vector<int> &A) {
    int count = 0;
    int i = 0;
    while(i<A.size()){
        if(A[i]==0 && count%2==0) count++;
        if(A[i]==1 && count%2==1) count++;
        i++;
    }
    return count;
}