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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 2e4 + 10;
const int INF = 1e9;

using namespace std;

vector<tuple<int,int,int>> e;
 
struct Dinic {
	int nodes,src,dst; // Cantidad de nodos, indice del nodo fuente, indice del nodo resumidero
	vector<int> dist,q,work; // Distancia de cada nodo respecto a la fuente, vector auxiliar para BFS, vector auxiliar para DFS
	struct edge {int to,rev;ll f,cap;}; // {nodo destino de la arista original, indice de la arista inversa en la lista de adyacencia del nodo destino, flujo actual de la arista original, capacidad maxima de la arista}
	vector<vector<edge>> adj; // Representacion del grafo como lista de adyacencia

	Dinic(int x):nodes(x),adj(x),dist(x),q(x),work(x){} // Constructor

	void add_edge(int s, int t, ll cap) {
		adj[s].pb((edge){t,sz(adj[t]),0,cap});
		adj[t].pb((edge){s,sz(adj[s])-1,0,0});
	}

	bool dinic_bfs() { //Construccion del nivel del grafo
		fill(dist.begin(), dist.end(), -1);
        dist[src]=0;
		int qt=0;
        q[qt++]=src;

		for (int qh=0; qh<qt; qh++) {
			int u=q[qh];
			forr(i,0,sz(adj[u])){
				edge &e=adj[u][i];
                int v=adj[u][i].to;
				if (dist[v]<0&&e.f<e.cap) {
                    dist[v]=dist[u]+1;
                    q[qt++]=v;
                }
			}
		}

		return dist[dst]>=0;
	}

	ll dinic_dfs(int u, ll f) { // Empujar flujo
		if (u==dst)
            return f;

		for (int &i=work[u]; i<sz(adj[u]); i++) {
			edge &e=adj[u][i];
			if (e.cap<=e.f)
                continue;
			int v=e.to;
			if (dist[v]==dist[u]+1) {
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if (df>0) {
                    e.f+=df;
                    adj[v][e.rev].f-=df;
                    return df;
                }
			}
		}

		return 0;
	}

	ll max_flow(int _src, int _dst) {
		src=_src;
        dst=_dst;
		ll result=0;

		while (dinic_bfs()) {
			fill(work.begin(), work.end(), 0);
			while (ll delta=dinic_dfs(src,INF))
                result+=delta;
		}

		return result;
	}

    vector<int> min_cut(Dinic &dinic) {
        vector<int> min_cut;
        vector<bool> visited(dinic.nodes, false);
        queue<int> q;

        q.push(dinic.src);
        visited[dinic.src] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            min_cut.push_back(u);

            for (const auto &e : dinic.adj[u]) {
                if (!visited[e.to] && e.f < e.cap) {
                    visited[e.to] = true;
                    q.push(e.to);
                }
            }
        }

        return min_cut;
    }
};

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
        int u,v,d; cin >> u >> v >> d;
        v+= n;
        e.pb({u,v,d});
    }

    int res = 1e9;
    int x;
    int a = 0 , b = 1e9;
    while (a <= b) {
        x = (a+b)/2;
        Dinic dinic(2*n + 2);
        int S = 0, T = 2*n + 1;

        forn(i,n)
        {
            dinic.add_edge(S, i+1, 1);        // S -> cada fábrica, capacidad 1
            dinic.add_edge(n+i+1, T, 1);      // cada aeropuerto -> T, capacidad 1
        }

        for (auto [u, v, d] : e)
        {
            if (d <= x)   // solo las aristas permitidas para este x
            {
                dinic.add_edge(u, v, 1);    // fábrica u -> aeropuerto v, capacidad 1
            }
        }

        ll flujo = dinic.max_flow(S, T);

        if(flujo == n)
        {
            b = x-1;
            res = min(res,x);
        }
        else
        {
            a = x+1;
        }
    }

    Dinic finalCheck(2*n + 2);
    int S = 0, T = 2*n + 1;
    forn(i,n)
    {
        finalCheck.add_edge(S, i+1, 1);
        finalCheck.add_edge(n+i+1, T, 1);
    }
    for (auto [u, v, d] : e)
    {
        finalCheck.add_edge(u, v, 1);  // sin filtro, todas las aristas
    }
    if (finalCheck.max_flow(S, T) < n)
    {
        cout << -1 << nl;
    }
    else
    {
        cout << res << nl;
    }
    
    return 0;
}