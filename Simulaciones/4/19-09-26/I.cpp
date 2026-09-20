#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (int) b-1; i>= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

const int MAXN = 400+6;
const int INF  = MAXN*1e3;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << endl
#endif

vector<pair<int,int>> T;
vector<pair<int,int>> adj[MAXN];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
bitset<MAXN> visited;
int dist[MAXN];
map<int,int> temp;

void dijkstra(int r){
    visited.reset();
    fill(dist, dist+MAXN, INF);
    pq.push({0,r});
    dist[r] = 0;
    while (!pq.empty())
    {
        int v = pq.top().snd; pq.pop();
        if(visited[v] || T[temp[v]].fst > T[temp[r]].fst) continue;
        visited[v] = 1;
        for(auto [u,w] : adj[v])
        {
            if(dist[v]+w < dist[u])
            {
                dist[u] = dist[v]+w;
                pq.push({dist[u], u});
            }
        }
    }
}

void dijkstra2(int r){
    visited.reset();
    fill(dist, dist+MAXN, INF);
    pq.push({0,r});
    dist[r] = 0;
    while (!pq.empty())
    {
        int v = pq.top().snd; pq.pop();
        if(visited[v] || T[temp[v]].fst < T[temp[r]].fst) continue;
        visited[v] = 1;
        for(auto [u,w] : adj[v])
        {
            if(dist[v]+w < dist[u])
            {
                dist[u] = dist[v]+w;
                pq.push({dist[u], u});
            }
        }
    }
}

// Estructura para guardar las consultas y su orden original
struct Query {
    int u, v, k, id;
};

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

int n, r; 
    if (!(cin >> n >> r)) return 0;
    
    vector<pair<int,int>> T(n);
    vector<int> u_temps; // Para guardar las temperaturas únicas
    
    forn(i, n) {
        cin >> T[i].first;
        T[i].second = i;
        u_temps.push_back(T[i].first);
    }

    // Extraer las temperaturas únicas y ordenarlas de menor a mayor
    sort(u_temps.begin(), u_temps.end());
    u_temps.erase(unique(u_temps.begin(), u_temps.end()), u_temps.end());
    int num_u = u_temps.size();

    vector<vector<int>> adj(n, vector<int>(n, INF));
    forn(i, n) adj[i][i] = 0;

    forn(i, r) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }

    int q; cin >> q;
    vector<Query> q0, q1;
    
    // 1. Leer consultas y traducir K a la cantidad REAL de planetas
    forn(i, q) {
        int u, v, k, t; cin >> u >> v >> k >> t;
        u--; v--;
        
        if (t == 0) {
            // Temperaturas más frías
            int k_idx = min(k, num_u) - 1;
            int target_temp = u_temps[k_idx];
            
            // Contamos cuántos planetas cumplen con esta temperatura o una más fría
            int eff_k = 0;
            forn(j, n) if(T[j].first <= target_temp) eff_k++;
            
            q0.push_back({u, v, eff_k, i});
        } else {
            // Temperaturas más calientes
            int k_idx = num_u - min(k, num_u);
            int target_temp = u_temps[k_idx];
            
            // Contamos cuántos planetas cumplen con esta temperatura o una más caliente
            int eff_k = 0;
            forn(j, n) if(T[j].first >= target_temp) eff_k++;
            
            q1.push_back({u, v, eff_k, i});
        }
    }

    // 2. Ordenar las consultas por nuestra cantidad real de planetas (eff_k)
    auto cmp = [](const Query& a, const Query& b) { return a.k < b.k; };
    sort(q0.begin(), q0.end(), cmp);
    sort(q1.begin(), q1.end(), cmp);

    vector<int> ans(q, -1);

    // --- PROCESAMIENTO T = 0 ---
    sort(T.begin(), T.end()); 
    vector<vector<int>> dist0 = adj;
    int idx = 0;
    
    for (int k = 1; k <= n; ++k) {
        int mid = T[k-1].second; 
        
        forn(i, n) {
            forn(j, n) {
                if (dist0[i][mid] != INF && dist0[mid][j] != INF) {
                    dist0[i][j] = min(dist0[i][j], dist0[i][mid] + dist0[mid][j]);
                }
            }
        }
        
        while (idx < (int)q0.size() && q0[idx].k == k) {
            int res = dist0[q0[idx].u][q0[idx].v];
            ans[q0[idx].id] = (res == INF) ? -1 : res;
            idx++;
        }
    }

    // --- PROCESAMIENTO T = 1 ---
    reverse(T.begin(), T.end()); 
    vector<vector<int>> dist1 = adj; 
    idx = 0;
    
    for (int k = 1; k <= n; ++k) {
        int mid = T[k-1].second; 
        
        forn(i, n) {
            forn(j, n) {
                if (dist1[i][mid] != INF && dist1[mid][j] != INF) {
                    dist1[i][j] = min(dist1[i][j], dist1[i][mid] + dist1[mid][j]);
                }
            }
        }
        
        while (idx < (int)q1.size() && q1[idx].k == k) {
            int res = dist1[q1[idx].u][q1[idx].v];
            ans[q1[idx].id] = (res == INF) ? -1 : res;
            idx++;
        }
    }

    // 3. Imprimir respuestas
    forn(i, q) {
        cout << ans[i] << nl;
    }

    return 0;
}