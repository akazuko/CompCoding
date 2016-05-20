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
#define pp pair<int, pair<int,int> >

int main(int argc, char const *argv[]) {
	int n,a,b,k;
	sd(n); sd(a); sd(b); sd(k);

	if (a==b) {
		cout<<0<<endl;
		return 0;
	}
	if (a>b){
		a=n-a+1;
		b=n-b+1;
	}

	int dp[k+1][b];
	for(int i= 1; i<=k; ++i){
		for(int x=1; x<b; ++x){
			if(x==b-1)
				dp[i][x] = 0;
			else if(i==1)
				dp[i][x] = b-1-max(1,2*x-b+1);
			else{
				dp[i][x] = 0;
				for(int j=max(1, 2*x-b+1); j<=b-1; ++j){
					if(j!=x){
						dp[i][x]+=dp[i-1][j];
					}
				}
			}
		}
	}
	for(int j=1; j<=k ; ++j){
	for(int i=0; i<b; ++i){
		cout<<dp[j][i]<<" ";
	
	}
	cout<<endl;}
	
	cout<<dp[k][a]<<endl;
	return 0;
}