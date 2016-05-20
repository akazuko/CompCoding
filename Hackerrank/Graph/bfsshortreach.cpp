#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void dij(bool vis[], int dist[], int s, int n, vector<int> g[]){
    priority_queue<pair<int,int> > q;
    for(int i=0; i<=n ; ++i) vis[i] = false;
    for(int i=0; i<=n ; ++i) dist[i] = INT_MAX;
    q.push(make_pair(0,s));
    dist[s] = 0;
    vector<int>::iterator i;
    while(!q.empty()){
        pair<int,int> node= q.top();
        q.pop();
        if(vis[node.second]) continue;
        for(i=g[node.second].begin(); i!=g[node.second].end(); ++i){
            if(!vis[*i] && dist[node.second] + 6 < dist[*i]){
                dist[*i] = dist[node.second] + 6;
                q.push(make_pair(-1*dist[*i],*i));
            }
        }
        vis[node.second] = true;
    }
}

int main() {
    int T,a,b;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n;
        cin>>m;
        vector<int> g[n+1];
        while(m--){
            cin>>a;
            cin>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int s;
        cin>>s;
        bool vis[n+1];
        int dist[n+1];
        dij(vis, dist, s, n, g);
        for(int i=1;i<=n;++i){
            if(i!=s){
                if(dist[i]==INT_MAX)
                    cout<<-1<<" ";
                else
                    cout<<dist[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
