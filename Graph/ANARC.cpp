#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <list>
#include <set>
#include <cmath>
#include <stdio.h>

using namespace std;

#define sd(x)	scanf("%d",&x); 
#define sll(x)	scanf("%lld",&x);
#define ss(x)	scanf("%s",&x);
#define ll long long
#define pll(x)	printf("%lld",x);
#define pd(x)	printf("%d",x);
#define ps(x)	printf("%s",x);

int main(int argc, char const *argv[])
{
	int cn = 1;
	while(1){
		int n;
		sd(n);
		if(n==0)
			break;
		int mat[n][n];
		
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				sd(mat[i][j]);

		int val1, val2, val3;
		val3=val2=val1=0;

		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				val1+=mat[i][j];
			}
		}
		
		int max_diff = 0;
		for(int i=0; i<n; ++i){
			int temp1=0;
			int temp2=0;
			for(int j=0; j<n; ++j)
				if(i!=j)
					temp1+=mat[i][j];
			for(int j=0; j<n; ++j)
				if(i!=j)
					temp2+=mat[j][i];
			// printf("%d %d\n", temp1, temp2);
			int k=temp2-temp1;
			if(k>0) //k*=-1;
				max_diff+=k;
		}
		printf("%d. %d %d\n", cn, val1, max_diff);
		cn++;
	}
	return 0;
}