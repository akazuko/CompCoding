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

ll power(ll a, ll b, ll p){
	ll res = 1;
	while(b){
		if(b&1) res = ((res%p)*(a%p))%p;
		b=b/2;
		a=((a%p)*(a%p))%p;
	}
	return res;
}

bool miillerTest(int d, int n) {
    int a = 2 + rand() % (n - 4);
    ll x = power(a, d, n);
    if (x == 1  || x == n-1)
       return true;
    while (d != n-1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}

bool isPrime(int n, int k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
         if (miillerTest(d, n) == false)
              return false; 
    return true;
}

int main(int argc, char const *argv[]) {
	// init();
	int t;
	sd(t);
	while(t--){
		ll m, n;
		sll(m); sll(n);
		for(ll i=m;i<=n; ++i){
			if(isPrime(i,4)) cout<<i<<endl;
		}
		cout<<endl;
	}
	return 0;
}