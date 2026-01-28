#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(ll i = (ll) b-1; i >= (ll) a; --i)
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

const ll MAXN = -1;
const ll INF = 1e9;

using namespace std;
 
ll tests;

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
        ll n, ax, ay, bx, by; cin >> n >> ax >> ay >> bx >> by;
        ll x[n], y[n];
        forn(i,n) cin >> x[i];
        forn(i,n) cin >> y[i];

        vector<pair<ll,ll>> v;
        forn(i,n) v.pb({x[i],y[i]});
        sort(v.begin(), v.end());

        vector<ll> top;
        vector<ll> bottom;
        ll i = 0;
        while(i<n)
        {
            ll curr = v[i].fst;
            top.pb(-INF);
            bottom.pb(INF);
            while (i<n && curr == v[i].fst)
            {
                top[top.size()-1] = max(top[top.size()-1], v[i].snd);
                bottom[bottom.size()-1] = min(bottom[bottom.size()-1], v[i].snd);
                i++;
            }
        }

        ll m = top.size();
        ll dp[m][2];
        dp[0][0] = abs(top[0]-ay) + (top[0] - bottom[0]);
        dp[0][1] = abs(bottom[0]-ay) + (top[0] - bottom[0]);
        forr(i,1,m)
        {
            ll barrido = (top[i] - bottom[i]);
            dp[i][0] = min(dp[i-1][0] + abs(top[i]-bottom[i-1]), dp[i-1][1] + abs(top[i]-top[i-1])) + barrido;
            dp[i][1] = min(dp[i-1][0] + abs(bottom[i]-bottom[i-1]), dp[i-1][1] + abs(bottom[i]-top[i-1])) + barrido;
        }

        cout <<  min(dp[m-1][0] + abs(by-bottom[m-1]), dp[m-1][1] + abs(by-top[m-1])) + bx-ax << nl;
    }
    
    return 0;
}