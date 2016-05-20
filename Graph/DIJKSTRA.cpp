#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
#include <queue>

using namespace std;

#define sd(x)	scanf("%d",&x); 
#define sll(x)	scanf("%lld",&x);
#define ss(x)	scanf("%s",x);
#define ll long long
#define pll(x)	printf("%lld",x);
#define pd(x)	printf("%d",x);
#define ps(x)	printf("%s",x);

#define pii pair<int,int>

int dijkstra(vector< pii > graph[], int n, int source, int dest){
	int dist[n+1];
	for(int i=1 ;i<=n; ++i)
		dist[i] = INT_MAX;
	bool visited[n+1];
	for(int i=1 ;i<=n; ++i)
		visited[i] = false;

	priority_queue<pii> q;

	dist[source]	= 0;
	q.push(pii(0,source));
	while(!q.empty()){
		int node = q.top().second;
		q.pop();
		if(visited[node])
			// break;
			continue;
		for(vector< pii >::iterator i=graph[node].begin(); i!=graph[node].end(); ++i){
			pii temp = *i;
			int u = temp.first;
			int u_weight = temp.second;

			if(!visited[u] && u_weight+dist[node] < dist[u]){
				dist[u] = u_weight+dist[node];
				q.push(pii(-1*dist[u], u));
			}
		}
		visited[node] = true;
	}
	return dist[dest];
}

int main(int argc, char const *argv[])
{
	int t; sd(t);
	while(t--){
		int v,k; sd(v); sd(k);
		vector< pii > graph[v+1];
		for(int i=1 ;i<=k; ++i){
			int n1, n2, w;
			sd(n1); sd(n2); sd(w);
			graph[n1].push_back(pii(n2,w));
		}
		int A,B; sd(A); sd(B);
		int minDist = dijkstra(graph, v, A, B);
		if(minDist==INT_MAX)
			printf("NO\n");
		else
			printf("%d\n", minDist);
	}
	return 0;
}