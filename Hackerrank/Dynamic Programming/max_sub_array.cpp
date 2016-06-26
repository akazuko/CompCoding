#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for(int i=0; i<n; ++i) cin>>A[i];
        int cur_sum = A[0];
        int ans_sum = A[0];
        int pre_sum = max(0,A[0]);
        for(int i=1; i<n;++i){
            cur_sum = max(cur_sum + A[i], A[i]);
            ans_sum = max(ans_sum, cur_sum);
            pre_sum += max(0,A[i]);
        }
        cout<<ans_sum<<" "<<(ans_sum<0 ? ans_sum : pre_sum)<<endl;
        
    }
    return 0;
}
