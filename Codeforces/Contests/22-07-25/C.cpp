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
        ll l,r; cin >> l >> r;
        
        ll res = r - l + 1; 
        ll d2 = r/2;
        ll d3 = r/3;
        ll d5 = r/5;
        ll d7 = r/7;

        res -= d2;
        res -= d3 - d3/2;
        res -= d5 - (d5/2 + d5/3) + d5/6;
        res -= d7 - (d7/2 + d7/3 + d7/5) + d7/6 + d7/10 + d7/15 - d7/30; 
        
        d2 = (l-1)/2;
        d3 = (l-1)/3;
        d5 = (l-1)/5;
        d7 = (l-1)/7;

        res += d2;
        res += d3 - d3/2;
        res += d5 - (d5/2 + d5/3) + d5/6;
        res += d7 - (d7/2 + d7/3 + d7/5) + d7/6 + d7/10 + d7/15 - d7/30; 

        cout << res << nl;
    }
    
    return 0;
}