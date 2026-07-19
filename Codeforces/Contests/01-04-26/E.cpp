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

    const int MAXN = 100;
    const int INF = 1e9;

    using namespace std;
    
    int tests;

    vector<pair<int,int>> adj[MAXN];
    vector dist(MAXN,INF);
    void dijkstra(int v, int n) {
        dist[v] = 0;

        // El infame algoritmo "Dikjstra":
        // Iterar una sola vez sobre los nodos en orden numérico
        forn(i, n) {
            if (dist[i] == INF) continue;

            for (auto u : adj[i]) {
                int b = u.first, w = u.second;
                if (dist[i] + w < dist[b]) {
                    dist[b] = dist[i] + w;
                }
            }
        }
    }

    int main()
    {
        #ifdef MILF
            freopen("../input.txt", "r", stdin);
        #endif
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n,m; cin >> n >> m;
        forn(i,m)
        {
            int v,u,w; cin >> v >> u >> w; v--; u--;
            adj[v].push_back({u,w});
            adj[u].push_back({v,w});
        }

        dijkstra(0,n);


        forn(i,n) if(dist[i] == INF) dist[i] = -1;
        forr(i,1,n)
        {
            cout << dist[i] << nl;
        }

        forn(i,n) adj[i].clear();
        dist.clear();
        
        return 0;
    }