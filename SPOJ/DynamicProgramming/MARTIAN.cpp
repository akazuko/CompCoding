#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <cmath>
#include <queue>
#include <strings.h>

using namespace std;

#define sd(x)   scanf("%d",&x); 
#define sll(x)  scanf("%lld",&x);
#define ss(x)   scanf("%s",x);
#define ll long long
#define pll(x)  printf("%lld",x);
#define pd(x)   printf("%d",x);
#define ps(x)   printf("%s",x);
#define pii pair<int,int>
#define pp pair<int, pair<int,int>>

int sum[500][500][2];
int dp[500][500];
int n,m;

void sol(){
	for(int i=0; i<n; i++){
		for(int j=0;j<m;++j){
			if(i==0 && j==0)      dp[i][j] = max(sum[i][j][0], sum[i][j][1]);
			else if(i==0 && j!=0) dp[i][j] = max(sum[i][j][0],dp[i][j-1] + sum[i][j][1]);
			else if(i!=0 && j==0) dp[i][j] = max(dp[i-1][j] + sum[i][j][0], sum[i][j][1]);
			else				  dp[i][j] = max(dp[i-1][j] + sum[i][j][0], dp[i][j-1] + sum[i][j][1]);
		}
	}
}
int main(int argc, char const *argv[])
{	
	int t;
	while(1){
		sd(n); sd(m);
		if(n==0 && m==0) break;
		for(int i=0; i<n; i++){
			for(int j=0;j<m;++j){
				sd(t);
				if(j==0) sum[i][j][0] = t;
				else 	 sum[i][j][0] = t + sum[i][j-1][0];
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0;j<m;++j){
				sd(t);
				if(i==0) sum[i][j][1] = t;
				else 	 sum[i][j][1] = t + sum[i-1][j][1];
			}
		}
		sol();
		pd(dp[n-1][m-1]);
		cout<<endl;
	}
	return 0;
}