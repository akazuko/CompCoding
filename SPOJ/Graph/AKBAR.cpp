#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	scanf("%d", &t);
	while(t--){

		long long n,r,m;
		scanf("%lld", &n); scanf("%lld", &r); scanf("%lld", &m);

		vector<long long> g[n+1];
		vector<bool> vis1(n+1, false);
		vector<long long> treno(n+1,1000000);
	
		long long a,b;
		for(long long i=0;i<r; ++i){
			scanf("%lld", &a); scanf("%lld", &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		
		int ans = 1;
		long long nono = 0;
		for(int i=0; i<m; ++i){
			scanf("%lld", &a); scanf("%lld", &b);

			if(ans==0) continue;

			if(treno[a]<nono){
				ans = 0;
				continue;
			}

			vector<bool> vis2(n+1, false);
			vector<long long> le(n+1,-1);

			queue<long long> data;
		
			vis2[a] = true;
			vis1[a] = true;
			le[a] = 0;
			data.push(a);
			
			while(!data.empty()){
				long long node = data.front();
				data.pop();

				for(vector<long long>::iterator i = g[node].begin(); i!=g[node].end() && le[node]<b; ++i) {

					if(treno[*i]<nono){
						ans = 0;
						break;
					}
				
					if(!vis2[*i]){
						vis1[*i] = vis2[*i] = true;
						treno[*i] = nono; 
						le[*i] = le[node]+1;
						data.push(*i);
					}	
				}
				if(ans == 0) break;
			}
			nono++;
		}

		if(ans) {
			for(int i=1; i<=n; ++i){
				if(!vis1[i]){
					ans = 0;
					break;
				}
			}

		}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}