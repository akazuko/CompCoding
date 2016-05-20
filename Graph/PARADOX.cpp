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


bool bfs(vector< pair<int,char> > *graph, int n, int start, bool *visited){
	queue<int> q;
	
	q.push(start);
	// visited[1]=true;
	int nof=0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		// printf("%d\n", node);
		// for(pair<int,char> neighNode : graph[node]){
		for(vector< pair<int,char> >::iterator neighNode = graph[node].begin(); neighNode!=graph[node].end(); ++neighNode){
			pair<int,char> temp = *neighNode;
			if(!visited[temp.first]){
				visited[temp.first] = true;
				if(temp.second=='f')
					nof++;
				q.push(temp.first);
			}
			if(temp.first == start)
				break;
		}
	}
	// printf("nof: %d\n", nof);
	if(nof%2==1)
		return true;
	return false;
}


int main(int argc, char const *argv[]){
	while(1){
		int n;
		sd(n);
		vector< pair<int,char> > graph[n+1];  
		if(n==0) break;
		char type[6];
		int node;
		for(int i=1; i<=n; ++i){
			sd(node);
			ss(type);
			// scanf("%s",type);
			if(type[0]=='f'){
				pair<int,char> temp;
				temp.first = node;
				temp.second = 'f';
				graph[i].push_back(temp);
			}
			if(type[0]=='t'){
				pair<int,char> temp;
				temp.first = node;
				temp.second = 't';
				graph[i].push_back(temp);
			}
		}

		// graph generated

		bool visited[n+1];
		for(int i=1; i<=n; ++i)
			visited[i]=false;
		bool res = true;
		for(int i=1 ; i<=n; ++i){
			// if(!visited[i]){
				bool ans = bfs(graph, n, i, visited);
				// printf("%d\n", ans);
				res = res & ans;
			// }
		}
		if(res)
			printf("PARADOX\n");
		else
			printf("NOT PARADOX\n");
		
	}
	return 0;
}