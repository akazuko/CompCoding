# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>
 
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
 
#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,a,b) for(int i=a;i<b;i++)
#define ALL(v) (v).begin(),(v).end()
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define pb push_back
#define mp make_pair


typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
#define INF (int)1e9
#define EPS (double)(1e-9)
#define PI (double)(3.141592653589793)

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)


//compute A*B
matrix mul(matrix A, matrix B) {
	int K = 2;
matrix C(K+1, vector<ll>(K+1));
REP(i,0, K) REP(j,0, K) REP(k,0, K)
	C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
return C;
}

// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

struct Tree
 {
 	Tree *left;
 	Tree *right;
 };

int main(void) {
	std::ios_base::sync_with_stdio (false);
	int T;
	scanf("%d",&T);
	double n,sum;
	while(T--) {
		scanf("%lf",&n);
		sum = 3*(long)(n/2) + 1;
		printf("%.0lf",sum);
	}


	return 0;
}
