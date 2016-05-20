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


bool vis[101];
bool val[101];

bool dfs(int node, vector< pii > graph[]){
	vis[node] = true;
	// printf("%d %d\n", node, val[node]);

	vector< pii >::iterator i;
	for(i=graph[node].begin(); i!=graph[node].end(); ++i){
		pii temp = *i;
		// printf("in %d : (%d,%d) --> val[] : %d \n", node, temp.first, temp.second, val[temp.first]);
		
		if(!vis[temp.first]){
			if(temp.second==0){
				if(val[node]==false)
					val[temp.first] = true;
				else
					val[temp.first] = false;
			}
			if(temp.second==1){
				if(val[node]==false)
					val[temp.first] = false;
				else
					val[temp.first] = true;
			}
			bool tempp = dfs(temp.first, graph);
			if(!tempp)
				return false;
		}
		else{
			if(temp.second == 0){
				if(val[node]==false && val[temp.first]==false)
					return false;
				else if(val[node]==true && val[temp.first]==true)
					return false;
			}
			else if(temp.second == 1){
				if(val[node]==false && val[temp.first]==true)
					return false;
				else if(val[node]==true && val[temp.first]==false)
					return false;
			}
		}
	}
	return true;
}

void init(int t){
	for(int i=1; i<=t; ++i){
			vis[i] = false;
			val[i] = false;
		}
}

int main(int argc, char const *argv[])
{
	int t;
	while(1){
		sd(t);
		if(t==0)
			break;
		
		vector< pii > graph[t+1];

		for(int i=1;i<=t;++i){
			int temp;
			char type[6];
			sd(temp);
			ss(type);
			if(type[0]=='f'){
				graph[i].push_back(make_pair(temp,0));
			}
			else{				
				graph[i].push_back(make_pair(temp,1));
			}
		}

		
		init(t);
		int res=1;
		for(int i=1; i<=t;++i){
			if(!vis[i]){
				val[i] = true;
				bool pool = dfs(i, graph);
				init(t);
				// printf("pool : %d\n", pool);
				if(!pool){
					res = 0;
					break;
				}
			}
		}
		if(res==0){
			printf("%s\n", "PARADOX");
		}
		else{
			printf("%s\n", "NOT PARADOX");
		}
	}
	return 0;
}