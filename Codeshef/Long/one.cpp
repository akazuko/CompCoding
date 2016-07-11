#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
	int n,q;
	cin>>n>>q;
	vector<long long> ar(n);
	for(int i=0; i<n; ++i) cin>>ar[i];

	sort(ar.begin(), ar.end());
	long long t;
	for(int i=0; i<q;++i){
		cin>>t;
		if(t<=ar[n-1] && t>=ar[0])  cout<<"Yes"<<endl;
		else 						cout<<"No"<<endl;
	}	
	return 0;
}