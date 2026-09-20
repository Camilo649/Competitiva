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

const int MAXN = 1e5 + 4;

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

ll lk[MAXN], len[MAXN];
ll find(ll x) {
    if(x == lk[x]) return x;
    return lk[x] = find(lk[x]);
}
bool same(ll x, ll y) {
    return find(x) == find(y);
}
void unite(ll x, ll y) {
    ll a = find(x);
    ll b = find(y);
    if (len[a] < len[b]) swap(a,b);
    len[a] += len[b];
    lk[b] = a;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m; cin >> n >> m;
    for (int i = 0; i < n; i++) lk[i] = i;
    for (int i = 0; i < n; i++) len[i] = 1;

    vector<tuple<ll,ll,ll>> edges;
    forn(i,m)
    {
        ll u,v,w; cin >> u >> v >> w;
        u--; v--;
        edges.pb({w,u,v});
        edges.pb({w,v,u});
    }

    sort(ALL(edges));

    ll ans = 0;
    forn (i,SZ(edges)) {
        if (!same(get<1>(edges[i]), get<2>(edges[i])))
        {
            unite(get<1>(edges[i]), get<2>(edges[i]));
            ans += get<0>(edges[i]);
        }
    }

    forn(i,n-1) if(!same(i,i+1)) {cout << "IMPOSSIBLE" << nl; return 0;} 

    cout << ans << nl;
    
    return 0;
}