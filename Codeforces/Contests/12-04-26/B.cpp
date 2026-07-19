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
        ll t,h,u; cin >> t >> h >> u;
        ll n = 0;

        ll mn = min(t,u);
        n += 4*mn;
        t-=mn; u-=mn;
        
        mn = min(t/2LL, h);
        n += mn*7;
        t-=2*mn; h-=mn;

        mn = min(t,h);
        n += 5*mn;
        t-=mn; h-=mn;

        if(t>1)
        {
            n += 3;
            t--;
            n += t*2;
            t = 0;
        }

        n += (t+h+u)*3;

        cout << n << nl;
    }
    
    return 0;
}