#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
#include <queue>

using namespace std;

#define sd(x)	scanf("%d",&x); 
#define sll(x)	scanf("%lld",&x);
#define ss(x)	scanf("%s",x);
#define ll long long
#define pll(x)	printf("%lld",x);
#define pd(x)	printf("%d",x);
#define ps(x)	printf("%s",x);

#define pii pair<int,int>

int main(int argc, char const *argv[])
{
	int t; sd(t);
	while(t--){
		int n,k;
		sd(n); sd(k);
		int dp[k+1];
		int list[k+1];
		int tmp;
		for(int i=1; i<=k; ++i)
			cin>>list[i];
		
		for(int i=1; i<=k; ++i)
			dp[i] = list[i];

		for(int w=1; w<=k; ++w){
			for(int i=1; i<w; ++i){
					if(list[i]==-1 || dp[w-i] == -1) continue;
					if(dp[w]==-1) dp[w] = dp[w-i] + list[i];
					else dp[w] = min(dp[w], dp[w-i] + list[i]);
			}
		}
		if(k==0)
			cout<<0<<endl;
		else
			cout<<dp[k]<<endl;
	}
	return 0;
}