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
#define GE
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 100;

using namespace std;

int tests;

int main()
{
    #ifdef GE
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int a[n][6];
    bitset<100> b;
    forn(i,n)
    {
        forn(j,6)
        {
            cin >> a[i][j];
            b[a[i][j]] = 1;
        }
    }

    if(n >= 2)
    {
        forn(i,6)
        {
            forn(j,6)
            {
                b[a[0][i]*10 + a[1][j]] = 1;
                b[a[1][j]*10 + a[0][i]] = 1;
            }
        }

        if(n >= 3)
        {
            forn(i,6)
            {
                forn(j,6)
                {
                    b[a[0][i]*10 + a[2][j]] = 1;
                    b[a[2][j]*10 + a[0][i]] = 1;
                }
            }

            forn(i,6)
            {
                forn(j,6)
                {
                    b[a[1][i]*10 + a[2][j]] = 1;
                    b[a[2][j]*10 + a[1][i]] = 1;
                }
            }
        }
    }

    int x = 0;
    while (b[x+1])
    {
        x++;
    }
    
    cout << x << nl;
    
    return 0;
}