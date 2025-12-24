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
    
    int n; cin >> n;
    int dp[MAXN][MAXN] = {};
    char grid[n+2][n+2];
    forr(i,1,n+1)
    {
        forr(j,1,n+1)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '*')
                dp[i][j] = 0;
        }
    }

    forn(i,n+2)
    {
        grid[i][0] = '*';
        grid[i][n+1] = '*';
    }
    forn(j,n+2)
    {
        grid[0][j] = '*';
        grid[n+1][j] = '*';
    }

    /*Dump Grid*/
    // forn(i,n+2)
    // {
    //     forn(j,n+2)
    //     {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << nl;
    // }
    // cout << nl;

    int k = 1;
    while(k<n+2 && grid[k][1] != '*')
    {
        dp[k][1] = 1;
        k++;
    }
    k = 1;
    while(k<n+2 && grid[1][k] != '*')
    {
        dp[1][k] = 1;
        k++;
    }

    /*Dump initial dp*/
    // forn(i,n+2)
    // {
    //     forn(j,n+2)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << nl;
    // }
    // cout << nl;

    forr(i,2,n+1)
    {
        forr(j,2,n+1)
        {
            if (grid[i][j] == '*')
                continue;
            dp[i][j] += dp[i-1][j] % M; 
            dp[i][j] += dp[i][j-1] % M;
        }
    }

    /*Dump final dp*/
    // forn(i,n+2)
    // {
    //     forn(j,n+2)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << nl;
    // }
    // cout << nl;

    cout << dp[n][n] % M << nl;

    return 0;
}