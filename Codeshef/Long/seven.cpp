#include <bits/stdc++.h>
using namespace std;
#define modd 1000000007
int main(int argc, char const *argv[]) {
	int n,q;

	cin>>n;
	vector<int> fr(n+1);
	vector<int> ans(n+1);
	for(int i=1; i<=n; ++i) cin>>fr[i];

	ans[0] = 0;
	
	cin>>q;
	int a,b,c;
	while(q--){
		cin>>a;
		if(a==1){
			cin>>b>>c;
			fr[b] = c;
		}
		else{
			cin>>b;
			int ans = 1;
			int cur = 1;
			while(cur<=n){
				ans = (ans%modd * fr[cur]%modd)%modd;
				// ans = ans*fr[cur];
				cur = cur + b;
			}
			cout<<to_string(ans)[0]<<" "<<(ans%modd)<<endl;
		}
	}
	return 0;
}