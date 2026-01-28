#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(ll i = (ll) b-1; i >= (ll) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((ll) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const ll MAXN = -1;
const ll INF = 1e9;

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
        ll n; cin >> n;
        ll a[n]; forn(i,n) cin >> a[i];

        ll dp[n+1];
        forn(i,n+1)
        {
            dp[i] = INF;
        }
        vector<ll> v;
        sort(a, a+n);
        v.pb(a[0]);
        dp[v[0]] = 1;
        forr(i,1,n)
        {
            if(a[i] != v.back()) 
            {
                v.pb(a[i]);
                dp[a[i]] = 1;
            }
        }

        ll m = v.size();
        if(m != n)
        {
            forr(i,1,n+1)
            {
                forn(j,m)
                {
                    ll d = v[j];
                    if(i*d <= n) dp[i*d] = min(dp[i*d], dp[i]+1);
                    else break;
                }
            }
        }

        forn(i,n+1)
        {
            if(dp[i] == INF) dp[i] = -1;
        } 
        forn(i,n)
        {
            cout << dp[i+1] << " ";
        }
        cout << nl;
    }
    
    return 0;
}