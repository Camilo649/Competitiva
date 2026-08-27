#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) sort(x.begin(), x.end())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int INF = -1;

using namespace std;

int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tests;

    while (tests--)
    {
        ll n; cin >> n;

        vector<ll> res;
        while (n!=0)
        {
            ll a = 1;
            while (a < 2*n && n%(2*a) == 0)
            {
                a*=2;
            }
            //cout << a << nl;
            ll m = n/a;
            ll b = 1;
            while (3*b <= m)
            {
                b*=3;
            }
            //cout << b << nl;
            res.pb(a*b);
            n-=a*b;
        }
        
        cout << SZ(res) << nl
        forn(i,SZ(res))
        {
            cout << res[i] << " "; 
        }
        cout << nl
    }
    
    return 0;
}