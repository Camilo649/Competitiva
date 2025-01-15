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

const int MAXN = -1;

using namespace std;
 
int t;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;

    while (t--)
    {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;

        int n = p1 + p2 + p3;
        if (n%2==1)
        {
            cout << -1 << nl;
        }
        else
        {
            int dp[p1+2][p2+2][p3+2] = {};
            forn(i,p2+2)
            {
                forn(j,p3+2)
                {
                    dp[0][i][j] = -1;
                }            
            }
            forn(i,p1+2)
            {
                forn(j,p3+2)
                {
                    dp[i][0][j] = -1;
                }            
            }
            forn(i,p1+2)
            {
                forn(j,p2+2)
                {
                    dp[i][j][0] = -1;
                }            
            }
            forr(i,1,p1+2)
            {
                forr(j,1,p2+2)
                {
                    forr(k,1,p3+2)
                    {
                        dp[i][j][k] = 1 + max(max(dp[i-1][j-1][k], dp[i-1][j][k-1]), dp[i][j-1][k-1]); 
                    }
                }
            }
            cout << dp[p1+1][p2+1][p3+1] << nl;
        } 
    }
    

    return 0;
}