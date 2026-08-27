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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;
const int INF = 1e9;

using namespace std;
 
int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,a,b,c; cin >> n >> a >> b >> c;

    int mx = max(max(a,b),c);

    int dp[n + mx + 1];
    forn(i,n + mx + 1)
    {
        dp[i] = -INF;
    }
    dp[0] = 0;
    forn(i,n)
    {
        dp[i+a] = max(dp[i]+1, dp[i+a]);
        dp[i+b] = max(dp[i]+1, dp[i+b]);
        dp[i+c] = max(dp[i]+1, dp[i+c]);
    }
    
    cout << dp[n] << nl;

    return 0;
}