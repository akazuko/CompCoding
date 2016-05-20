#include <iostream>
// #include <bits/stdc++.h>
#include <stack>
#include <list>
#include <set>
#include <cmath>
#include <stdio.h>

using namespace std;

#define sd(x)	scanf("%d",&x); 
#define sll(x)	scanf("%lld",&x);
#define ss(x)	scanf("%s",&x);
#define ll long long
#define pll(x)	printf("%lld",x);
#define pd(x)	printf("%d",x);
#define ps(x)	printf("%s",x);

/*
	Using pair in C++ :
	???
*/

int main(int argc, char const *argv[]){
	int n, m;
	sd(n); sd(m);
	int color[n+1];
	list<int> graph[n+1];
	int max_col=0;
	for(int i=1;i<=n;++i){
		sd(color[i]);
		if(color[i]>max_col)
			max_col=color[i];
	}
	list<int> v_k[max_col+1];

	// To generate the graph
	for(int i=1;i<=m;++i){
		int n1, n2;
		sd(n1); sd(n2);
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	// To generate the V(k)
	for(int i=1;i<=n;++i){
		v_k[color[i]].push_back(i);
	}

	int ans = 0;
	int cor_color = 0;

	for(int i=0; i<=max_col; ++i){
		set<int> q_k;
		for(list<int>::iterator node=v_k[i].begin(); node!= v_k[i].end(); ++node){
			for(list<int>::iterator neigh_nodes=graph[*node].begin(); neigh_nodes!= graph[*node].end(); ++neigh_nodes){
				if(color[*neigh_nodes]!=i)
					q_k.insert(color[*neigh_nodes]);
			}
		}
		int count = q_k.size();
		if(count > ans){
			ans = count;
			cor_color = i;
		}
	}

	printf("%d\n", cor_color);
	return 0;
}