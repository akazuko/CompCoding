#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,t;
    float ans;
    cin>>n;
    priority_queue<int> max;
    priority_queue<int> min;
    for(int i=0; i<n;++i){
        
        cin>>t;
        if(i==0) max.push(t);
        else if(!max.empty() && t<max.top()) max.push(t);
        else min.push(-1*t);
            
        int n1 = max.size();
        int n2 = min.size();
        
        if( n1 > n2 + 1 ){
            min.push(-1*max.top());
            max.pop();
        }
        else if(n2 > n1+1){
            max.push(-1*min.top());
            min.pop();
        }
        
        if((n1+n2)%2==0){
            ans = (max.top() + -1*min.top() )/2.0;
        }
        else{
            if(n1 > n2){
                ans = max.top();
            }
            else{
                ans = -1*min.top();
            }
        }
        printf("%.1f\n",ans);
    }
    
    return 0;
}
