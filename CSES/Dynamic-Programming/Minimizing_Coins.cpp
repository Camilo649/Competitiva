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

const int MAXN = 2e6+6;
const int INF = 1e7;

using namespace std;
 
int tests;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,x; cin >> n >> x;
    int c[n];
    forn(i,n)
    {
        cin >> c[i];
    }

    int dp[MAXN];
    dp[0] = 0;
    forr(i,1,x+1)
    {
        dp[i] = INF;
        forn(j,n)
        {
            if (i-c[j] < 0)
                continue;
            dp[i] = min(dp[i], 1 + dp[i-c[j]]);
        }
    }

    dp[x] == INF ? cout << -1 : cout << dp[x];
    cout << nl;
    
    return 0;
}