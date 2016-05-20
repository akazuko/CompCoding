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
int pval = 1000000007;
int main(int argc, char const *argv[])
{
	int R, G;
	sd(R); sd(G);
	int H=0;
	for(int i=1;i<=1000; ++i){
		if((i*(i+1))/2 > (R+G)){
			H = i-1;
			break;
		}
	}
	int dp[2][R+1];
	for(int h=0; h<=H; ++h){
		for(int r = 0; r<=R; ++r){
			if(h==0){
				if(r==R)
					dp[h%2][R] = 1;
				else
					dp[h%2][r] = 1;
			}
			else{
				dp[h%2][r] = 0;
				if(r>=h && r<=min(R,(h*(h+1))/2)) dp[h%2][r] = ((dp[h%2][r]%pval) + (dp[1-(h%2)][r-h])%pval)%pval; 
				if(r>=max(0,(h*(h+1))/2 - G) && r<=min(R,((h-1)*(h))/2)) dp[h%2][r] = ((dp[h%2][r]%pval) + (dp[1-(h%2)][r])%pval)%pval;
			}
		}
	}
	int temp = 0;
	for(int i=0;i<=R; ++i){
		temp = (temp%pval + dp[H%2][i]%pval)%pval;
	}
	cout<<temp<<endl;
	return 0;
}