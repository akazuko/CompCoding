#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    double N;
    cin>>N;
    vector<double> v(N);
    vector<double> v2(N);
    vector<double> rat(N);
    double j,val;
    for(j=0; j<N ; ++j){
        v[j] = 1; 
        v2[j] = 1;
    }
    for(j=0; j<N ; ++j){
        cin>>rat[j]; 
    }
    
    //v[0]=1;
    double k;
    for(j=0,k=1;j<N-1 && k<N; ++j,++k){
        if(rat[j] > rat[j+1])
            v[j] = v[j+1] + 1;
        else if(rat[j] < rat[j+1])
            v[j+1] = v[j] + 1;
        
        if(rat[k] > rat[k-1])
            v[k] = v[k+1] + 1;
        else if(rat[k] < rat[k-1])
            v[k+1] = v[k] + 1;
    }

    // for(j=0;j<N-1 ; ++j){
    //     if(rat[j] > rat[j+1])
    //         v[j] = v[j+1] + 1;
    //     else if(rat[j] < rat[j+1])
    //         v[j+1] = v[j] + 1;
    // }

    double sum = 0;
    for(j=0; j<N ; ++j){
        sum+=max(v[j],v2[j]); 
    }
    printf("%.0lf\n", sum);
    return 0;
}
