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
        ld c[n], p[n];
        forn(i,n)
        {
            cin >> c[i]; cin >> p[i];
        } 

        ld f[n]; f[n-1] = c[n-1];
        dforn(i,n-1)
        {
            f[i] = max(f[i+1], f[i+1]*(1-(p[i]/100)) + c[i]);
        }

        cout << fixed << setprecision(10) << f[0] << nl;
    }
    
    return 0;
}