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

int main(int argc, char const *argv[]) {
	int t;
	sd(t);
	while(t--){
		int N,K;
		sd(N); sd(K);
		float dp[N+1][K+1];
		for(int n=1;n<=N; ++n){
			for(int k=1;k<=K;++k){
				if(n==1)
					dp[n][k] = 1/6.0;
				else{
					dp[n][k] = dp[n-1][k] + (dp[n-1][k-1] + )/6;
				}
			}
		}
		cout<<(int)(dp[N][K]*100)<<endl;
	}
	return 0;
}