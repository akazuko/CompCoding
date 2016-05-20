#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <climits>
#include <cmath>

using namespace std;

void dfs(vector<int> g[], int dis[], bool vis[], int node){
	vis[node] = true;
	for(vector<int>::iterator i = g[node].begin(); i!=g[node].end(); ++i){
		if(!vis[*i]){
			dis[*i] = dis[node] + 1;
			dfs(g,dis,vis,*i);
		}
	}
}

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	
	vector<int> g1[n+1];
	int dis[n+1];
	bool vis[n+1];

	for(int i=1;i<n; ++i){
		int a,b;
		scanf("%d",&a);
		scanf("%d",&b);
		g1[a].push_back(b);
		g1[b].push_back(a);
	}

	for(int i=0; i<=n; ++i){
		vis[i] = false;
		dis[i] = INT_MAX;
	}

	dis[1] = 0;
	dfs(g1,dis,vis,1);
	int node = -1;
	int max_dis = -1;
	
	for(int i=1; i<=n; ++i){
		if(vis[i]){
			if(dis[i]>max_dis){
				max_dis = dis[i];
				node = i;
			}
		}
	}

	for(int i=0; i<=n; ++i){
		vis[i] = false;
		dis[i] = INT_MAX;
	}
	dis[node] = 0;
	dfs(g1,dis,vis,node);

	node = -1;
	max_dis = -1;
	
	for(int i=1; i<=n; ++i){
		if(vis[i]){
			if(dis[i]>max_dis){
				max_dis = dis[i];
				node = i;
			}
		}
	}
	printf("%d\n", dis[node]);
	return 0;
}