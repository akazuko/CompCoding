#include <iostream>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(int i = 0; i< n ; ++i)cin>>a[i];
	    int start = 0;
	    int end = n-1;
	    int mid;
	    while(a[start] > a[end]){
	        mid = start + (end-start)/2;
	        if(a[mid] > a[end]) start = mid + 1;
	        else                end   = mid;
	    }
	    cout<<a[start]<<endl;
	}
	return 0;
}
