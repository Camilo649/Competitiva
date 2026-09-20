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

const int MAXN = 1e5 + 9;
const ll INF   = 1e15; 

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

priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;
bitset<2*MAXN> visited;
ll dist[2*MAXN];
vector<pair<ll,ll>> adj[2*MAXN];

void dijkstra(ll r) {
    fill(dist, dist+2*MAXN, INF);
    pq.push({0,r});
    dist[r] = 0;
    while (!pq.empty()) {
        int v = pq.top().second; pq.pop();
        if (visited[v]) continue;
            visited[v] = 1;
        for (auto [u, w] : adj[v]) {
            if (dist[v]+w < dist[u]) {
                dist[u] = dist[v]+w;
                pq.push({dist[u],u});
            }
        }
    }
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
    forn(i,m)
    {
        ll u,v,w; cin >> u >> v >> w;
        u--; v--;
        adj[u].pb({v,w});
        adj[u].pb({v+n,w/2});
        adj[u+n].pb({v+n,w});
    }

    dijkstra(0);

    cout << dist[2*n-1] << nl;
    
    return 0;
}