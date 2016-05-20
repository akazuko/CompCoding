#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <stdio.h>
#include <vector>
using namespace std;


#define sd(x)   scanf("%d",&x); 
#define sll(x)  scanf("%lld",&x);
#define ss(x)   scanf("%s",x);
#define ll long long
#define pll(x)  printf("%lld",x);
#define pd(x)   printf("%d",x);
#define ps(x)   printf("%s",x);

#define pii pair<int,int>

int count_var = 0;

void dfs(vector<int> g[], int node, bool vis[]){
    // cout<<"1"<<node<<"\n";
    vis[node] = true;
    count_var++;
    for(vector<int>::iterator i = g[node].begin(); i!=g[node].end(); ++i){
        if(!vis[*i])
            dfs(g,*i,vis);
    }
}

int main(int argc, char const *argv[])
{
    int t;sd(t);
    int T=1;
    while(T<=t){
        int n; sd(n);
        int ans = 0;
        vector<int> g[n+1];
        bool vis[n+1];
        for(int i=1; i<=n; ++i){
            int tmp;
            sd(tmp);
            g[i].push_back(tmp);
        }
        for(int i=0; i<=n; ++i) vis[i] = false;
        for(int i=1; i<=n; ++i){
            if(!vis[i]){
                count_var = 0;
                dfs(g,i, vis);
                ans = max(ans,count_var);
            }
        }
        printf("Case #%d: %d\n", T, ans);
        T++;
    }
    return 0;
}