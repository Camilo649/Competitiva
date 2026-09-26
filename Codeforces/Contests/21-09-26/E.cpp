#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;
const ll INF = 1e18;

using namespace std;

// Debugging
#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    if (DBG) os << "[";
    for (auto& x : v) os << x << (DBG ? ", " : " ");
    return DBG ? os << "]" : os;
}

template<typename S, typename T> ostream& operator<<(ostream& os, const pair<S, T>& p) {
    return os << (DBG ? "(" : "") << p.fst << (DBG ? ", " : " ") << p.snd << (DBG ? ")" : "");
}

int tests;

vector<ll> F;
void fact(int n) {
    F.clear();
    for (ll p = 2; p * p <= n; p++) {
        while (n%p == 0) {
            n /= p;
            F.pb(p);
        }
    }
    if (n > 1) F.pb(n);

    sort(ALL(F));
}

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
        ll n,k; cin >> n >> k;
        map<ll,ll> h;
        forn(i,n)
        {
            ll a; cin >> a;
            h[a]++;
        }

        ll dp[n+1];
        fill(dp, dp+n+1, INF);
        forn(i,k+1) dp[i] = 0;
        forr(i,k+1,n+1)
        {
            fact(i);
            //print(a); print(F);
            for(auto d : F)
            {
                dp[i] = min(dp[i], 1LL + d*dp[i/d]);
            }
            //print(dp[a]);
        }

        ll ans = 0;
        for(auto [a,c] : h)
        {
            ans += dp[a]*c;
        }
        cout << ans << nl;
    }
    
    return 0;
}