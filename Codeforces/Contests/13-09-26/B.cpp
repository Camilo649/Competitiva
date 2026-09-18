#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((ll) x.size())
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
const ll INF = 2e18;

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
        ll n,m; cin >> n >> m;
        ll a[n]; forn(i,n) cin >> a[i];
        if(m == 1)
        {
            ll mx = -INF;
            forn(i,n) mx = max(mx,a[i]);
            cout << mx << nl;
            continue;
        }

        ll sum = 0;
        priority_queue<ll> pq;
        forn(i,m-1) {pq.push(a[i]); sum += a[i];}

        ll ans = -INF;
        forr(i,m-1,n)
        {
            ans = max(ans, m*a[i] - sum);
            if(a[i] < pq.top())
            {
                sum -= pq.top();
                sum += a[i];
                pq.pop();
                pq.push(a[i]);
            }
        }

        cout << ans << nl;
    }
    
    return 0;
}