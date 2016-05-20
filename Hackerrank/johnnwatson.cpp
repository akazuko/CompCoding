#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    double N=0,K;
    int Q;
    //double array[N];//, array2[N];
    double val;
    int i;
    cin>>N;
    cin>>K;
    cin>>Q;
    
    vector<double> v(N);
    double j;
    for(j = 0 ;j<N ; ++j){
        //printf("%d\n", i);
        cin>>val;
        v[fmod((j+K),N)] = val;
    }
    for(i=0;i<Q;++i){
        cin>>val;
        cout<<v[val]<<endl;
    }
    return 0;
}
