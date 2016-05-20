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

int check(vector<int> pos, int n, int dist, int C){
	int lastpos = pos[0];
	int cows = 1;
	for(int i=1;i<n;++i){
		if(pos[i]-lastpos>=dist){
			cows++;
			if(cows==C)
				return 1;
			lastpos = pos[i];
		}	
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	int t; sd(t);
	while(t--){
		int n,C;
		sd(n); sd(C);
		vector<int> pos;
		
		for(int i=0; i<n; ++i){
			int temp;
			cin>>temp;
			pos.push_back(temp);
		}
		sort(pos.begin(), pos.end());
		int start = 0;
		int end = pos[n-1]-pos[0];
		while(start+1<end){
			int mid = start+(end-start)/2;
			if(check(pos, n, mid, C)){
				start = mid;
			}
			else{
				end = mid;
			}
		}
		cout<<start<<endl;
	}
	return 0;
}