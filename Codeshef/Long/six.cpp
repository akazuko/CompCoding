#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {
	int n,m;
	cin>>n>>m;

	int arr[n][m];

	for(int i=0; i<n; ++i)
		for(int j=0; j<m ;++j)
			cin>>arr[i][j];

	int q; 
	cin>>q;
	
	int a,b;
	long long ans, maxx, sum, temp;
	while(q--){
		cin>>a>>b;
		ans = INT_MAX;
		for(int i=0; i<n; ++i){
			for(int j=0; j<m ; ++j){
				if(i+a>n || j+b>m) continue;

				maxx = INT_MIN;
				sum = 0;
				for(int x = 0; x<a; ++x){
					for(int y = 0; y<b; ++y){
						maxx = max(maxx, arr[i+x][j+y]);
						sum+=arr[i+x][j+y];
					}
				}
				temp = maxx*a*b - sum;
				ans = min(ans,temp);
				// cout<<"maxx : "<<maxx<<" ans : "<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}