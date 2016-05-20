#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<string,pair<int,pair<int,int> > > 
using namespace std;

bool cmp(pii a, pii b){
	if(( a.second.first == b.second.first) && (a.second.second.first == b.second.second.first) && a.second.second.second == b.second.second.second ) return a.first<b.first;
	if( ( a.second.first == b.second.first) && (a.second.second.first == b.second.second.first) ) return a.second.second.second < b.second.second.second;
	else if (( a.second.first == b.second.first) ) return  a.second.second.first > b.second.second.first;
	else return a.second.first > b.second.first;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector< pii > ar(n);
	for(int i=0; i<n; ++i){
		string name;
		int p,q,r;
		cin>>name>>p>>q>>r;
		ar[i] = make_pair(name,make_pair(p,make_pair(q,r)));
	}
	sort(ar.begin(), ar.end(), cmp);
	for(int i=0; i<n; ++i){
		cout<<ar[i].first<<endl;
	}
	return 0;
}