#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
#include <queue>

using namespace std;
int pval = 1000000007;

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

	int dp[2][b];
	int csum[2][b];

	for(int i= 1; i<=k; ++i){
		for(int x=0; x<b; ++x){
			if(x==0){
				dp[i%2][x] = 0;
			}
			else if(x==b-1){
				dp[i%2][x] = 0;
			}
			else if(i==1){
				dp[i%2][x] = b-1-max(1,2*x-b+1);
			}
			else{
				dp[i%2][x]= ( (csum[1-(i%2)][b-1]%pval) - (csum[1-(i%2)][max(1,2*x-b+1)-1]%pval) - (csum[1-(i%2)][x]%pval) + (csum[1-(i%2)][x-1])%pval )%pval; 
			}
		}

		csum[i%2][0]=0;
		for(int x=1; x<b; ++x){
			csum[i%2][x] = ((csum[i%2][x-1]%pval) + (dp[i%2][x]%pval))%pval;
		}

		/*
		cout<<"dp"<<endl;
		for(int i=0; i<b; ++i)
			cout<<dp[0][i]<<" ";
		cout<<endl;
		for(int i=0; i<b; ++i)
			cout<<dp[1][i]<<" ";
		cout<<endl;
		cout<<"csum"<<endl;
		for(int i=0; i<b; ++i)
			cout<<csum[0][i]<<" ";
		cout<<endl;
		for(int i=0; i<b; ++i)
			cout<<csum[1][i]<<" ";
		cout<<endl;
		*/


	}
	cout<<(dp[k%2][a])%pval<<endl;
	return 0;
}