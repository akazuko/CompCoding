#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}
int main(int argc, char const *argv[]) {
	int n;
	int a,b;
	int t;
	scanf("%d",&t);
	while(t--){
	scanf("%d",&n);
	
	vector< pair<int,int> > v(n);
	
	for(int i=0; i<n; ++i) {
		scanf("%d",&a);
		scanf("%d",&b);
		v[i] = make_pair(a,b);
	}
	
	sort(v.begin(),v.end(),cmp);
	for(int i=0; i<n; ++i){
		printf("%d %d\n",v[i].first,v[i].second);
	}
	}
	return 0;
}