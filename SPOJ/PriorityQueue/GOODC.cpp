#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct MAXX {
    bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs) const {
      if(lhs.first==rhs.first) return lhs.second>rhs.second;
      return lhs.first<rhs.first;
    }
};

struct MINN {
    bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs) const {
      if(lhs.first==rhs.first) return lhs.second<rhs.second;
      return lhs.first>rhs.first;
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m,a,b;
    scanf("%d",&n);
    scanf("%d",&m);
    //cin>>n>>m;
    priority_queue<pair<int,int> ,vector<pair<int,int> >, MAXX > maxx;
    priority_queue<pair<int,int> ,vector<pair<int,int> >, MINN > minn;
    map<int,int> done;
    vector<int> val(n+1,0);
    for(int i=1; i<n+1; ++i){
        maxx.push(make_pair(0,i));
        minn.push(make_pair(0,i));
        done[i] = 0;
    }
    int c=0;
    for(int i=0; i<m; ++i ){
        //cin>>a>>b;
        scanf("%d",&a);
        scanf("%d",&b);
        //if(c==n){cout<<"Make noise"<<endl; continue;}
        if(c==n){printf("Make noise\n"); continue;}
        if(a==1){
            done[b] = 1;
            c++;
        }
        else{
            val[b]+=1;
            maxx.push(make_pair(val[b], b));
            minn.push(make_pair(val[b], b));
        }
        
        if(c==n){printf("Make noise\n"); continue;}
        //if(c==n){cout<<"Make noise"<<endl; continue;}
        
        while(!maxx.empty() && (done[maxx.top().second]==1 || maxx.top().first!=val[maxx.top().second]) ) maxx.pop();
        
        while(!minn.empty() && (done[minn.top().second]==1 || minn.top().first!=val[minn.top().second]) ) minn.pop();
        
        printf("%d %d\n",maxx.top().second, minn.top().second);
        //cout<<maxx.top().second<<" "<<minn.top().second<<endl;
        
    }
    return 0;
}
