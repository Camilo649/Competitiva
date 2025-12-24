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

const int MAXX = 1e6+6;
const int M = 1e9 + 7;

using namespace std;
 
int tests;

int main()
{
    // #ifdef MILF
    //     freopen("../input.txt", "r", stdin);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,x; cin >> n >> x;
    int c[n+1];
    c[0] = 0;
    forn(i,n)
    {
        cin >> c[i+1];
    }
    sort(c, c+n);

    vector<vector<ll>> dp(2, vector<ll>(MAXX, 0));
    dp[0][0] = 1; dp[1][0] = 1;

    forr(i,1,n+1)
    {
        forr(j,1,x+1)
        {
            dp[i%2][j] = dp[(i-1)%2][j];
            if (j-c[i] < 0)
                continue;
            dp[i%2][j] += (dp[i%2][j-c[i]]) % M;
        }
    }

    cout << dp[n%2][x] % M << nl;
    
    return 0;
}