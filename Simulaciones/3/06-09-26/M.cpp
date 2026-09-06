#include <bits/stdc++.h>

#define forr(i,a,b) for(ll i = (ll) a; i < (ll) b; ++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(ll i = (ll) b-1; i >= (ll) a; --i)
#define dforn(i,n) dforr(i,0,n)
#define SZ(x) ((ll) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const ll MAXN = 1e5 + 4;
const ll INF = 1e15 + 4;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

ll n,m,K;
bitset<11*MAXN> visited;
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
vector<pair<ll,ll>> adj[11*MAXN];
vector<pair<ll,ll>> adj1[11*MAXN];
vector<pair<ll,ll>> adj2[11*MAXN];
ll dist[11*MAXN];

void dijkstra(int r)
{
    fill(dist, dist+11*MAXN, INF);
    pq.push({0,r});
    dist[r] = 0;
    while (!pq.empty())
    {
        int v = pq.top().second; pq.pop();
        if(visited[v]) continue;
            visited[v] = 1;
        for(auto [u,w] : adj[v]) {
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

    cin >> n >> m >> K;
    forn(i,m)
    {
        ll u,v,f,w; cin >> u >> v >> f >> w;
        u--; v--;
        adj1[u].pb({v,f});
        adj1[v].pb({u,f});
        adj2[u].pb({v,(w < 1 ? INF : w)});
        adj2[v].pb({u,(w < 1 ? INF : w)});
    }

    forn(k,K+1)
        forn(i,n)
        {
            for(auto [a,f] : adj1[i])
                adj[k*n + i].pb({k*n + a, f});
            if(k < K)
                for(auto [a,w] : adj2[i])
                    adj[k*n + i].pb({(k+1)*n + a, w});
        }

    dijkstra(0);

    ll ans = INF;
    forn(k,K+1) ans = min(ans, dist[k*n + n-1]);

    cout << ans << nl;

    return 0;
}