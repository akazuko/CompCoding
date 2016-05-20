//Iterative approach
#include <iostream>
using namespace std;
#define MOD 1000000007
long long mpow(long long a, long long b)
{
	long long ret = 1;
        while(b)
        {
            if(b & 1) ret = (ret * a) % MOD;
            b >>= 1;
            a = (a * a) % MOD;
        }
        return ret;
}
int main() {
// your code goes here
        long long i,t,a,b;
        cin>>a>>b;
        cout<<mpow(a,b)<<endl;
        return 0;
}
