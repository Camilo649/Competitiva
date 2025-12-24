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

const int MAXN = 1e6 + 6;
const int INF = 1e6;

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
    
    int n; cin >> n;

    int dp[MAXN];
    forn(i,n)
    {
        dp[i] = INF;
    }
    dp[n] = 0;

    dforn(i,n+1)
    {
        if (dp[i] != INF)
        {
            string s = to_string(i);
            forn(j,s.size())
            {
                int num = s[j] - '0';
                if (i - num >= 0)
                {
                    dp[i-num] = min(dp[i-num], 1+dp[i]);
                }
            }
        } 
    }

    cout << dp[0] << nl;
    
    return 0;
}