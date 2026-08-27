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

const int MAXN = 1e5 + 3;
const ll INF = 0xfffffffffffffff;

using namespace std;
 
vector<pair<int,int>> adj[MAXN];
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
bitset<MAXN> visited;
ll dist[MAXN];

void dijkstra(int r) {
    fill(dist, dist+MAXN, INF);
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
        int u,v,w; cin >> u >> v >> w; u--; v--;
        adj[u].pb({v,w});
    }

    dijkstra(0);

    forn(i,n)
    {
        cout << dist[i] << " ";
    }
    cout << nl;
    
    return 0;
}