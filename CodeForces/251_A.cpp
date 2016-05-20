#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[]) {
	
	int n,k;
	long long ans = 0;
	cin>>n>>k;

	vector<int> ar(n);
	
	for(int i=0; i<n; ++i) cin>>ar[i];
	
	for(int i=0; i<n-2; ++i){
		
		int start = i+1;
		int end = n-1;
		while(start<=end){
			int mid = start + (end-start)/2;
			if((ar[mid]-ar[i])<= k) start = mid+1;
			else end = mid-1;
		}

		long long val = start - i - 1;
		if(val>=2)
			ans+= val*(val-1)/2;
	}
	cout<<ans;
	return 0;
}