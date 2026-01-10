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

ll fact(ll n) {
    ll x = 1;
    forr(i,1,n+1)
    {
        x *= i;
    }
    return x;
}

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
        ll n,k,q; cin >> n >> k >> q;
        ll a[n]; forn(i,n) cin >> a[i];

        ll ans = 0;
        ll m = 0;
        forn(i,n)
        {
            while (i<n && a[i] <= q)
            {
                m++;
                i++;
            }
            if(m >= k)
            {
                ans += ((m-k+2)*(m-k+1))/2;
            }
            m=0;
        }

        cout << ans << nl;
    }
    
    return 0;
}