#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main(){
	int n;
	cin>>n;
	map< pair<int,int>, string > m;
	for(int i=0; i<n; ++i) {
		int a,b;
		cin>>a>>b;
		string l;
		cin>>l;
		m[make_pair(a,b)] = l;
	}
	int t;
	cin>>t;
	for(int i=0;i<t;++i){
		int a,b;
		cin>>a>>b;
		if(m[make_pair(a,b)]!=""){
			cout<<m[make_pair(a,b)]<<endl;
		}
	}
	return 0;
}