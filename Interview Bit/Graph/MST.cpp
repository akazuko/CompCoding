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
#define pp pair<int, pair<int,int> >
vector<int> P(10000);
vector<int> rankk(10000);
vector<pii> G[3001];
priority_queue<pp> q;

int find_set(int x){
	if(x!=P[x])
		P[x] = find_set(P[x]);
	return P[x];
}

int merge_sets(int x, int y){
	int Px = find_set(x);
	int Py = find_set(y);
	if(rankk[Px] > rankk[Py])
		P[Py] = Px;
	else
		P[Px] = Py;
	if(rankk[Px] == rankk[Py])
		rankk[Py] = rankk[Py] + 1;
}

int create_set(int x){
	P[x] = x;
	rankk[x] = 0;
}
int netsum = 0;
void mst(){
	while(!q.empty()){
		pair<int,int> temp = q.top().second;
		int ew = q.top().first;
		q.pop();

		if(find_set(temp.first)!=find_set(temp.second)){
			merge_sets(temp.first, temp.second);
			netsum+=-1*ew;
		}
	}
}

int main(int argc, char const *argv[]) {
	int n;
	sd(n);
	int m;
	sd(m);
	
	for(int i=0;i<m; ++i){
		int a,b,c;
		sd(a); sd(b); sd(c);
		q.push(make_pair(-1*c,make_pair(a,b)));
	}
	
	for(int i=0;i<=n; ++i){
		create_set(i);
	}
	
	int r;
	sd(r);

	mst();
	cout<<netsum;
	return 0;
}