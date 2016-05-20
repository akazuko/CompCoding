#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <cmath>
#include <queue>
#include <strings.h>

using namespace std;

#define sd(x)	scanf("%d",&x); 
#define sll(x)	scanf("%lld",&x);
#define ss(x)	scanf("%s",x);
#define ll long long
#define pll(x)	printf("%lld",x);
#define pd(x)	printf("%d",x);
#define ps(x)	printf("%s",x);
#define pii pair<int,int>
#define pp pair<int, pair<int,int>>

int main(int argc, char const *argv[]) {
	int t; sd(t);
	while(t--){
		string A;
		string B;
		cin>>A;
		cin>>B;
		int la = A.size();
		int lb = B.size();
		int dp[la+1][lb+1];
		for(int i=0;i<=la;++i){
			for(int j=0;j<=lb;++j){
				if(i==0)
					dp[i][j] = j;
				else if(j==0)
					dp[i][j] = i;
				else if(A[i-1]==B[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
			}
		}
		cout<<dp[la][lb]<<endl;
	}
	return 0;
}