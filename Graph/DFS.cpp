#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <list>
#include <cmath>
#include <stdio.h>

using namespace std;


#define sd(x)	scanf("%d",&x); 
#define sll(x)	scanf("%lld",&x);
#define ss(x)	scanf("%s",x);
#define ll long long
#define pll(x)	printf("%lld",x);
#define pd(x)	printf("%d",x);
#define ps(x)	printf("%s",x);

#define pii pair<int,int>

char ch[] = "ALLIZZWELL";

string inp[101];
bool vis[101][101];

bool dfsr(int n, int m, int starti, int startj, int point){
	vis[starti][startj] = true;
	bool asd;
	if(point>9){
			return true;
	}

		int tempr = starti-1;
		int tempc = startj-1;
		if(tempr>=0 && tempr<n && tempc>=0 && tempc<m && inp[tempr][tempc]==ch[point] && !vis[tempr][tempc]){
			vis[tempr][tempc] = true;
			asd =dfsr(n, m, tempr, tempc, point+1);
			if(asd) return true;
			vis[tempr][tempc] = false;
		}

		tempr = starti-1;
		tempc = startj;
		if(tempr>=0 && tempr<n && tempc>=0 && tempc<m && inp[tempr][tempc]==ch[point] && !vis[tempr][tempc]){
			vis[tempr][tempc] = true;
			asd =dfsr(n, m, tempr, tempc, point+1);
			if(asd) return true;
			vis[tempr][tempc] = false;
		}

		tempr = starti-1;
		tempc = startj+1;
		if(tempr>=0 && tempr<n && tempc>=0 && tempc<m && inp[tempr][tempc]==ch[point] && !vis[tempr][tempc]){
			vis[tempr][tempc] = true;
			asd =dfsr(n, m, tempr, tempc, point+1);
			if(asd) return true;
			vis[tempr][tempc] = false;
		}

		tempr = starti;
		tempc = startj-1;
		if(tempr>=0 && tempr<n && tempc>=0 && tempc<m && inp[tempr][tempc]==ch[point] && !vis[tempr][tempc]){
			vis[tempr][tempc] = true;
			asd =dfsr(n, m, tempr, tempc, point+1);
			if(asd) return true;
			vis[tempr][tempc] = false;
		}

		tempr = starti;
		tempc = startj+1;
		if(tempr>=0 && tempr<n && tempc>=0 && tempc<m && inp[tempr][tempc]==ch[point] && !vis[tempr][tempc]){
			vis[tempr][tempc] = true;
			asd =dfsr(n, m, tempr, tempc, point+1);
			if(asd) return true;
			vis[tempr][tempc] = false;
		}

		tempr = starti+1;
		tempc = startj-1;
		if(tempr>=0 && tempr<n && tempc>=0 && tempc<m && inp[tempr][tempc]==ch[point] && !vis[tempr][tempc]){
			vis[tempr][tempc] = true;
			asd =dfsr(n, m, tempr, tempc, point+1);
			if(asd) return true;
			vis[tempr][tempc] = false;
		}

		tempr = starti+1;
		tempc = startj;
		if(tempr>=0 && tempr<n && tempc>=0 && tempc<m && inp[tempr][tempc]==ch[point] && !vis[tempr][tempc]){
			vis[tempr][tempc] = true;
			asd =dfsr(n, m, tempr, tempc, point+1);
			if(asd) return true;
			vis[tempr][tempc] = false;
		}

		tempr = starti+1;
		tempc = startj+1;
		if(tempr>=0 && tempr<n && tempc>=0 && tempc<m && inp[tempr][tempc]==ch[point] && !vis[tempr][tempc]){
			vis[tempr][tempc] = true;
			asd =dfsr(n, m, tempr, tempc, point+1);
			if(asd) return true;
			vis[tempr][tempc] = false;
		}

		vis[starti][startj] = false;
		return false;
}

int main(int argc, char const *argv[])
{
	int t; sd(t);
	while(t--){
		int n,m; sd(n); sd(m);
		for(int i=0;i<n;++i){
			cin>>inp[i];
		}
		bool res = false;
		bool ans = false;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
					vis[i][j] = false;

		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(inp[i][j]==ch[0]){
					// printf("%d %d\n",i,j );
					ans = dfsr(n,m,i,j,1);
					res = res | ans;
					if(res) break;
				}
			if(res) break;
			}
		}
		if(res)
			printf("%s\n", "YES");
		else
			printf("%s\n", "NO");
	}
	
	return 0;
}