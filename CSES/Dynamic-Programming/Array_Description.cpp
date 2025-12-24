#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e5 + 6;
const int MAXM = 1e2 + 3;
const ll M = 1e9 + 7;

using namespace std;
 
int tests;
ll dp[MAXN][MAXM] = {};

int main()
{
    // #ifdef MILF
    //     freopen("../input.txt", "r", stdin);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m; cin >> n >> m;
    int x[n+1];
    forn(i,n) cin >> x[i+1];

    if(x[1] != 0) dp[1][x[1]] = 1;
    else
    {
        forr(j,1,m+1) dp[1][j] = 1;
    }
    
    forr(i,2,n+1)
    {
        if (x[i] == 0)
        {
            forr(j,1,m+1)
            {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % M;
            }
        }
        else
        {
            dp[i][x[i]] = (dp[i-1][x[i]-1] + dp[i-1][x[i]] + dp[i-1][x[i]+1]) % M;
        }
    }

    int res = 0;
    forr(j,1,m+1) res = (res + dp[n][j]) % M;
    cout << res % M << nl;
    
    return 0;
}