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

const int MAXN = 1e3 + 3;
const int MAXX = 1e5 + 5;

using namespace std;
 
int tests;
int dp[MAXN][MAXX] = {};

int main()
{
    // #ifdef MILF
    //     freopen("../input.txt", "r", stdin);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x; cin >> n >> x;
    int h[n], s[n];
    forn(i,n) cin >> h[i];
    forn(i,n) cin >> s[i];

    forr(i,1,n+1)
    {
        forr(j,1,x+1)
        {
            dp[i][j] = max(j-h[i-1] >= 0 ? s[i-1] + dp[i-1][j-h[i-1]] : 0, dp[i-1][j]);
        }
    }

    cout << dp[n][x] << nl;
    
    return 0;
}