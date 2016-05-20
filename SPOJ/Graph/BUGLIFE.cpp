#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


bool dfs(vector<int> g[], bool vis[], int n, int col[], int node){
	vis[node] = true;
	for(vector<int>::iterator i = g[node].begin(); i!=g[node].end(); ++i){
		if(!vis[*i]){
			col[*i] = 1-(col[node])%2;
			bool temp = dfs(g,vis,n,col,*i);
			if(!temp)
				return false;
		}
		else{
			if(col[*i]==col[node])
				return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	int t;
	int cas=1;
	scanf("%d",&t);
	while(cas<=t){
		int n,k;
		
		scanf("%d",&n);
		scanf("%d",&k);

		vector<int> g[n+1];
		int a,b;
		
		while(k--){
			scanf("%d",&a);
			scanf("%d",&b);
			g[a].push_back(b);
			g[b].push_back(a);

		}

		bool vis[n+1];
		int col[n+1];
		for(int i=1; i<=n; ++i){
			vis[i] = false;
			col[i] = -1;
		}
		bool ans = true;
		for(int i=1; i<=n; ++i){
			if(!vis[i]){
				col[i] = 0;
				ans = dfs(g,vis,n,col,i);
				if(!ans)
					break;
			}
		}

		printf("Scenario #%d:\n",cas);
		if(ans)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
		cas++;
	}
	return 0;
}