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
const double EPS = 1e-10;

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
    
    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        char d[n]; 
        int x[n]; 
        forn(i,n)
        {
            cin >> d[i];
            cin >> x[i];
        }

        cout << (n-1)+n << " " << d[0] << nl;
        forn(i,n-1)
        {
            cout << "Z " << x[i] << nl;
            if (d[i] == 'N')
            {
                if (d[i+1] == 'W')
                {
                    cout << 'L' << nl;
                }
                else
                {
                     cout << 'R' << nl;
                }
            }
            if (d[i] == 'S')
            {
                if (d[i+1] == 'E')
                {
                    cout << 'L' << nl;
                }
                else
                {
                     cout << 'R' << nl;
                }
            }
            if (d[i] == 'W')
            {
                if (d[i+1] == 'S')
                {
                    cout << 'L' << nl;
                }
                else
                {
                     cout << 'R' << nl;
                }
            }
            if (d[i] == 'E')
            {
                if (d[i+1] == 'N')
                {
                    cout << 'L' << nl;
                }
                else
                {
                     cout << 'R' << nl;
                }
            }
        }
        cout << "Z " << x[n-1] << nl;
    }
    
    return 0;
}