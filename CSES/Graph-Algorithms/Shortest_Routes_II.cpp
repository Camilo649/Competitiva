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

const int MAXN = 503;
const ll INF = 1e15+5;

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

ll adj[MAXN][MAXN];

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m,q; cin >> n >> m >> q;
    forn(i,n) forn(j,n) adj[i][j] = INF;
    forn(i,m)
    {
        ll u,v,w; cin >> u >> v >> w;
        u--; v--;
        adj[u][v] = min(w, adj[u][v]);
        adj[v][u] = min(w, adj[v][u]);
    }   

    ll dist[n][n];
    forn(i,n) {
        forn(j,n) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INF; // INF es un valor enorme
        }
    }

    forn(k,n) {
        forn(i,n) {
            forn(j,n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    forn(i,q)
    {
        int u,v; cin >> u >> v;
        u--; v--;
        cout << (dist[u][v] == INF ? -1 : dist[u][v]) << nl;
    }
    
    return 0;
}