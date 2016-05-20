#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		int two = 2;
		int five = 5;
		int sum2 = 0;
		int sum5 = 0;
		cin>>n;
		int temp;
		while(1){
			temp = n/two;
			if(temp==0) break;
			sum2+=temp;
			two*=2;
		}
		while(1){
			temp = n/five;
			if(temp==0) break;
			sum5+=temp;
			five*=5;
		}
		cout<<min(sum2,sum5)<<endl;
	}
	return 0;
}