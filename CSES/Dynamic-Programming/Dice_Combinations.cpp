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

const int MAXN = 1e6 + 16;
const ll M = 1e9 + 7;

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
    
    int n; cin >> n;

    ll dp[MAXN] = {};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    dp[6] = 1;

    forn(i,n+1)
    {
        dp[i] += ((i<=0) ? 0 : dp[i-1]) % M;
        dp[i] += ((i<=1) ? 0 : dp[i-2]) % M;
        dp[i] += ((i<=2) ? 0 : dp[i-3]) % M;
        dp[i] += ((i<=3) ? 0 : dp[i-4]) % M;
        dp[i] += ((i<=4) ? 0 : dp[i-5]) % M;
        dp[i] += ((i<=5) ? 0 : dp[i-6]) % M;
    }

    cout << dp[n]%M << nl;
    
    return 0;
}