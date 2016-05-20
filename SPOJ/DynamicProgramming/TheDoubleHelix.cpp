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

int binsearch(vector<int> arr, int val){
	int start = 0;
	int end = arr.size()-1;
	int mid;
	while(start<=end){
		mid = start + (end-start)/2;
		if(arr[mid] == val)
			return mid;
		else if(arr[mid] > val)
			end = mid-1;
		else
			start = mid+1;
	}
	return -1;
}

int main(int argc, char const *argv[]) {
	while(1){
		int n; sd(n);
		if(n==0) break;
		vector<int> A(n);
		for(int i=0;i<n; ++i) sd(A[i]);
		int n2; sd(n2);
		vector<int> B(n2);
		for(int i=0;i<n2; ++i) sd(B[i]);

		vector<int> extra(n);
		for(int i=0;i<n;++i) extra[i] = binsearch(B, A[i]);

		vector<int> sumA(n);
		vector<int> sumB(n2);

		sumA[0] = A[0];
		for(int i=1; i<n; ++i) sumA[i] = sumA[i-1] + A[i];
		sumB[0] = B[0];
		for(int i=1; i<n2; ++i) sumB[i] = sumB[i-1] + B[i];

		int prevA = -1;
		int prevB = -1;
		int ans = 0;

		for(int i=0; i<n; ++i){
			if(extra[i] == -1) continue;
			if(prevA==-1){
				ans += max(sumA[i], sumB[extra[i]]);
				prevA = i;
				prevB = extra[i];
			}
			else{
				ans += max(sumA[i] - sumA[prevA], sumB[extra[i]] - sumB[prevB]);
				prevA = i;
				prevB = extra[i];	
			}
		}
		if(extra[n-1]==-1){
			if(prevA!=-1)
				ans += max(sumA[n-1] - sumA[prevA], sumB[n2-1] - sumB[prevB]);
			else{
				ans += max(sumA[n-1], sumB[n2-1]);
			}
		}
		else{
			ans += sumB[n2-1] - sumB[prevB];
		}
		cout<<ans<<endl;
	}
	return 0;
}