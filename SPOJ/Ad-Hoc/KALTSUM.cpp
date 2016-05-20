#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
int main(int argc, char const *argv[]) {
	int n,q;
	scanf("%d", &n);
	scanf("%d", &q);
	
	vector<long long> sum(n+1);
	vector<long long > ar(n);

	for(int i=0; i<n; ++i)
		scanf("%lld", &ar[i]);
	
	sum[0] = 0;
	sum[1] = ar[0];
	for(int i=2; i<=n; ++i)
		sum[i] = sum[i-1] + ar[i-1];

	for(int i=0;i<q; ++i){
		long long  a,b;
		int k;
		scanf("%lld", &a);
		scanf("%lld", &b);
		scanf("%d", &k);	
		int start = a;
		int end = start + k - 1;
		long long ans = 0;
		int it = 0;
		while(end<=b){
			if(it==0){
				ans = ans + (sum[end] - sum[start-1]);
				it=1;
			}
			else{
				ans = ans + -1*(sum[end] - sum[start-1]);
				it=0;
			}

			start = end + 1;
			end = start + k -1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}