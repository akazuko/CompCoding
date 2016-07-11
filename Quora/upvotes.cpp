#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std; 

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 100007;
int N, K, in[MAX];
int length_inc[2][MAX], length_dec[2][MAX];

int main()
{
    scanf("%d%d", &N, &K);
    REP(i, N) scanf("%d", in+i);

    FOR(i, 0, N-1)
    {
        length_inc[0][i] = 1 + (i && in[i] >= in[i-1] ? length_inc[0][i-1] : 0);
        length_dec[0][i] = 1 + (i && in[i] <= in[i-1] ? length_dec[0][i-1] : 0);
    }
    FORD(i, N-1, 0)
    {
        length_inc[1][i] = 1 + (i < N-1 && in[i] >= in[i+1] ? length_inc[1][i+1] : 0);
        length_dec[1][i] = 1 + (i < N-1 && in[i] <= in[i+1] ? length_dec[1][i+1] : 0);
    }

    ll ninc = 0, ndec = 0; // number of increasing / decreasing subranges
    REP(i, K-1)
    {
        ninc += length_inc[0][i];
        ndec += length_dec[0][i];
    }

    FOR(i, K-1, N-1)
    {
        ninc += min(K, length_inc[0][i]);
        ndec += min(K, length_dec[0][i]);
        printf("%lld\n", ninc - ndec);
        ninc -= min(K, length_dec[1][i-(K-1)]);
        ndec -= min(K, length_inc[1][i-(K-1)]);
    }

    return 0;
}