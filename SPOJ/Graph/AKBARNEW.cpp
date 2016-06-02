#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	scanf("%d", &t);
	while(t--){
		int n,r,m;
		scanf("%d", &n); scanf("%d", &r); scanf("%d", &m);

		vector<int> g[n+1];
		vector<int> nodes_covered_by_this_node(n+1,-1);
		vector<int> inp_strength(n+1,-1);
		
		int a,b;
		for(int i=0;i<r; ++i){
			scanf("%d", &a); scanf("%d", &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		
	    bool ans = true;

		for(int i=0; i<m; ++i){
			scanf("%d", &a); scanf("%d", &b);
			nodes_covered_by_this_node[a] = b;
			inp_strength[a] = b;
		}


		vector<bool> vis(n+1, false);
		queue<int> data;
		
			vis[1] = true;
			data.push(1);
			while(!data.empty()){
				int node = data.front();
				data.pop();

				for(vector<int>::iterator iii = g[node].begin(); iii!=g[node].end(); ++iii) {
					if(!vis[*iii] ){
						data.push(*iii);
					}
					vis[*iii] = true;
					if(nodes_covered_by_this_node[node] < nodes_covered_by_this_node[*iii] -1 && inp_strength[node] == -1)
						nodes_covered_by_this_node[node] = 	nodes_covered_by_this_node[*iii]-1;
					if(inp_strength[*iii] == -1)
						nodes_covered_by_this_node[*iii] = max(nodes_covered_by_this_node[*iii], nodes_covered_by_this_node[node] - 1);
				}
			}

	    for(int i=1; i<=n; ++i){
	    	if(nodes_covered_by_this_node[i]<0){
	    		ans = false;
	    		break;
	    	}
	    }

		if(ans) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}