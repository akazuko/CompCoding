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

typedef struct {
    int low;
    int high;
    int sum;
}DPInfoType;

int main(void) {
	std::ios_base::sync_with_stdio (false);
	int T;
	scanf("%d",&T);
	int i,j,k;
	double count;
	int l,m,n;
	while(T--) {
		double *arr1,*arr2, *arr3;
		int *arr4,*arr5;
		
		s(l);
		arr1 = (double *) malloc(sizeof(double)*l);
		REP(i,0,l) sf(arr1[i]);
		s(m);
		
		arr2 = (double *) malloc(sizeof(double)*m);
		arr4 = (int *)malloc(sizeof(int)*l);
		
		j=0;
		REP(i,0,m) {
			sf(arr2[i]);
			if(arr2[i] >= arr1[j]) {arr4[j] = i;++j;}
		}

		if(j<l)
			REP(i,j,l) 
			if(arr4[j] < arr2[m-1])
				arr4[i] = -1/*arr4[i-1]*/;
			else 
			arr4[i] = arr4[i-1];

		s(n);
		arr3 = (double *) malloc(sizeof(double)*n);
		arr5 = (int *)malloc(sizeof(int)*m);
		
		j=0;
		REP(i,0,n) {
			sf(arr3[i]);
			if(arr3[i] >= arr2[j]) {arr5[j] = i;++j;}
		}
		if(j<m)
			
			REP(i,j,m) 
			if(arr2[j] < arr3[n-1])
			arr5[i] = -1/*arr5[i-1]*/;
			else 
			arr5[i] = arr5[i-1];


		count = 0;
		if(arr2[m-1] < arr1[0] || arr3[n-1] < arr2[0]) {
			printf("%.0lf\n",0.0);
			break;
		}
		//else if(arr1[l-1]<=arr2)
		//else
	/*	REP(i,0,l){
			REP(j,i,m){
				if(arr1[i] <= arr2[j])
				REP(k,j,n){
					if(arr2[j] <= arr3[k]) {
						count += n-k; break;
					}
				}
				//rintf("%.0lf\n",count);
				
			}
		}
	*/
		for(int i=0; i<l && arr4[i]!=-1;++i){
			/*REP(j,arr4[i],m)*/for(int j=i; j<m && arr5[j]!=-1;++j) {
				count += n - arr5[j];
			}
		}

		printf("%.0lf\n",count);

	}

	

	return 0;

}
