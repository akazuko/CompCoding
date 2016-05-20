#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <list>
#include <queue>
#include <cmath>
#include <stdio.h>
#include <algorithm>

using namespace std;


#define sd(x)	scanf("%d",&x); 
#define sll(x)	scanf("%lld",&x);
#define ss(x)	scanf("%s",x);
#define ll long long
#define pll(x)	printf("%lld",x);
#define pd(x)	printf("%d",x);
#define ps(x)	printf("%s",x);

#define pii pair<int,int>

vector<int> A(100000);
vector<int> B(100000);
bool ataken[100000];
bool btaken[100000];
vector<int> p(100000);
// vector<int> pB(100000);
vector< pii > graph[100000];
bool vis[100000];
int d[100000];

void dijA(int n, int start){
	
	for(int i= 0;i<n; ++i){
		vis[i] = false;
		d[i] = INT_MAX;
	}
	
	priority_queue< pii > s;

	s.push(pii(0,start));
	d[start] = 0;
	
	vector<pii>::iterator i;
	while(!s.empty()){
		int node = s.top().second;
		s.pop();
		if(vis[node]) continue;
		for(i=graph[node].begin(); i!= graph[node].end(); ++i){
			pii temp = *i;
			if(!vis[temp.first] && temp.second+d[node] < d[temp.first] && find(A.begin(), A.end(), temp.first) != A.end() ) {
				d[temp.first] = temp.second + d[node];
				s.push(pii(-1*d[temp.first], temp.first));
			}
		}
	    vis[node] = true;
	}
}

void dijB(int n, int start){
	
	for(int i= 0;i<n; ++i){
		vis[i] = false;
		d[i] = INT_MAX;
	}
	
	priority_queue< pii > s;

	s.push(pii(0,start));
	d[start] = 0;
	
	vector<pii>::iterator i;
	while(!s.empty()){
		int node = s.top().second;
		s.pop();
		if(vis[node]) continue;
		for(i=graph[node].begin(); i!= graph[node].end(); ++i){
			pii temp = *i;
			if(!vis[temp.first] && temp.second+d[node] < d[temp.first] && find(B.begin(), B.end(), temp.first) != B.end() ){
				d[temp.first] = temp.second + d[node];
				s.push(pii(-1*d[temp.first], temp.first));
			}
		}
	    vis[node] = true;
	}
}

void dijC(int n, int start){
	
	// for(int i= 0;i<n; ++i){
	// 	vis[i] = false;
	// 	d[i] = INT_MAX;
	// }
	
	priority_queue< pii > s;

	s.push(pii(0,start));
	d[start] = 0;
	
	vector<pii>::iterator i;
	while(!s.empty()){
		int node = s.top().second;
		s.pop();
		if(vis[node]) continue;
		for(i=graph[node].begin(); i!= graph[node].end(); ++i){
			pii temp = *i;
			if(!vis[temp.first] && temp.second+d[node] < d[temp.first]){
				d[temp.first] = temp.second + d[node];
				p[temp.first] = node;
				s.push(pii(-1*d[temp.first], temp.first));
			}
		}
	    vis[node] = true;
	}
}

int main(int argc, char const *argv[])
{
	int n,m,a,b;
	sd(n); sd(m); sd(a); sd(b);

	int temp,u,v,w;
	for(int i=0; i<a;++i){
		sd(temp);
		A[i] = temp;
	}
	for(int i=0; i<b;++i){
		sd(temp);
		B[i] = temp;
	}
	for(int i=0; i<m; ++i){
		sd(u); sd(v); sd(w);
		graph[u].push_back(pii(v,w));
		graph[v].push_back(pii(u,w));
	}


	for(int i= 0;i<n; ++i){
		vis[i] = false;
		d[i] = INT_MAX;
		p[i] = -1;
	}
	

	dijC(n,0);

	// for(int i=0; i<n; ++i)
	// 	printf("%d ", vis[i]);
	// printf("\n");

	int mina = INT_MAX;
	int inda = 0;
	int minb = INT_MAX;
	int indb = 0;

	for(int i=0; i<a;++i){
		if(d[A[i]]<mina){
			mina = d[A[i]];
			inda = A[i];
		}
	}

	//
	printf("%d\n", inda);
	for(int i= 0;i<n; ++i){
		vis[i] = false;
		d[i] = INT_MAX;
	}
	temp = p[inda];
	while(temp!=-1){
		vis[temp] = true;
		temp = p[temp];
	}
	for(int i= 0;i<n; ++i){
		p[i] = -1;
	}
	///
	dijC(n, inda);

	for(int i=0; i<b;++i){
		if(d[B[i]]<minb){
			minb = d[B[i]];
			indb = B[i];
		}
	}

	///
	printf("%d\n", indb);
	for(int i= 0;i<n; ++i){
		vis[i] = false;
		d[i] = INT_MAX;
	}
	temp = p[indb];
	while(temp!=-1){
		vis[temp] = true;
		temp = p[temp];
	}
	for(int i= 0;i<n; ++i){
		p[i] = -1;
	}
	///
	dijC(n, indb);

	ll ans = mina + minb + d[n-1];
	printf("%lld\n", ans);
	return 0;
}