#include <bits/stdc++.h>

#define modd 1000000007
using namespace std;

long long triangle[1000][1000];

void makeTriangle() {
    int i, j;
    triangle[0][0] = 1%modd; // C(0, 0) = 1

    for(i = 1; i < 1000; i++) {
        triangle[i][0] = 1%modd; // C(i, 0) = 1
        for(j = 1; j <= i; j++) {
            triangle[i][j] = (triangle[i - 1][j - 1]%modd + triangle[i - 1][j]%modd)%modd;
        }
    }
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	int n,k, noo;
	makeTriangle();

	while(t--){
		cin>>n>>k;
		noo = 0;
		vector<int> arr(n);
		for(int i=0; i<n; ++i) cin>>arr[i];
		
		for(int i=0; i<n; ++i) 
			if(arr[i]==0)
				noo++;

		int start = 0;
		long long val = 1;
		long long sum = 0;

		if(k%2==0)  start = 0;
		else		start = 1;
		int nn = n - noo;
		if(nn==0){
			cout<<0<<endl;
			continue;
		}
		// cout<<"nn : "<<nn<<endl;
		while(start<=min(nn,k)){
			// if((k%2==0 && start%2==0) || (k%2==1 && start%2==1))
				// sum = ( sum%modd + val%modd )%modd;
			sum = (sum%modd + triangle[nn][start]%modd)%modd;
			// start++;
			// val = ( (val/start)%modd * (n-start+1)%modd) %modd;
			start+=2;
			// val = ( val * ((n-start+1)) ) / start;
			// val = combi(n,start);
		}
		if(noo > 0 && k%2==1)
			sum = (sum + 1)%modd;
		cout<<sum%modd<<endl;
	}
	return 0;
}