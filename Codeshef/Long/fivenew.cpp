#include <bits/stdc++.h>

#define modd 1000000007
using namespace std;

vector<int> bcof(int n, int k){
	vector<int> ans;
	ans.push_back(1);
	int te;
	for(int i=1; i<=k+1; ++i){
		te = (ans[i-1]*(n-i+1))/i;
		ans.push_back(te);
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	int n,k;
	while(t--){
		cin>>n>>k;
		vector<int> arr(n);
		for(int i=0; i<n; ++i) cin>>arr[i];
		int i = k%2;
		int ans = 0;
		vector<int> bc = bcof(n,k);
		while(i<=k/2){
			ans = (ans%modd + bc[2*i + k%2]%modd)%modd;
			i++;
		}
		cout<<ans<<endl;
	}
	return 0;
}