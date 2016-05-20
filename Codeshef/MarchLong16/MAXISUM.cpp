#include <iostream>
#include <stdio.h>

#define sd(x)	scanf("%d",&x); 
#define sll(x)	scanf("%lld",&x);
#define ss(x)	scanf("%s",&x);
#define ll long long
#define pll(x)	printf("%lld",x);
#define pd(x)	printf("%d",x);
#define ps(x)	printf("%s",x);

using namespace std;

void merge(ll *A, ll *B, ll start, ll mid, ll end){
	ll n1 = mid-start+1;
	ll n2 = end-mid; 
	ll Al[n1];
	ll Bl[n1];
	ll Ar[n2];
	ll Br[n2];
	for(int i=start, j=0;i<=mid; ++i, j++){
		Al[j]=A[i];
		Bl[j]=B[i];
	}
	for(int i=mid+1, j=0;i<=end; ++i, j++){
		Ar[j]=A[i];
		Br[j]=B[i];
	}
	int one,two,k;
	one=two=0;
	k=start;
	while(one<n1 && two<n2){
		if(Al[one]*Bl[one]>Ar[two]*Br[two]){
			A[k] = Al[one];
			B[k] = Bl[one];
			one++;
			k++;
		}
		else{
			A[k] = Ar[two];
			B[k] = Br[two];
			two++;
			k++;
		}
	}
	while(one<n1){
		A[k] = Al[one];
		B[k] = Bl[one];
		one++;
		k++;
	}
	while(two<n2){
		A[k] = Ar[two];
		B[k] = Br[two];
		two++;
		k++;
	}
	
}

void msort(ll *A, ll *B, ll start, ll end){
	if(start<end){
		ll mid = start + (end-start)/2;
		msort(A, B, start, mid);
		msort(A, B, mid+1, end);
		merge(A, B, start, mid, end);
	}
}

int main(int argc, char const *argv[])
{
	int T;
	sd(T);
	while(T--){
		ll n,k;
		sll(n);
		sll(k);
		ll A[n];
		ll B[n];
		for(int i=0; i<n; ++i)
			sll(A[i]);
		for(int i=0; i<n; ++i)
			sll(B[i]);
		for(int i=0; i<n; ++i){
			if(A[i]<0 && B[i]<0){
				A[i]*=-1; B[i]*=-1;
			}
			// else if(A[i]>0 && B[i]<0){
			// 	A[i]*=-1; B[i]*=-1;
			// }
		}
		msort(A, B, 0, n-1);
		A[0]+=k;
		ll res=0;
		for(int i=0; i<n; ++i)
			res+= A[i]*B[i];
		pll(res);
		printf("\n");
	}
	return 0;
}