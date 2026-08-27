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

const int MAXN = 1e5+5;
const int MAXM = 2e5+10;

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

vector<pair<int,int>> adj[MAXN];
bitset<MAXM> used;
vector<int> circuit;

// n = cantidad de nodos, m = cantidad de aristas
// adj guarda pares {nodo_destino, id_arista}
void hierholzer(int n, int m, int start) {
    vector<int> currPath;
    currPath.push_back(start);

    while (!currPath.empty()) {
        int currNode = currPath.back();
        while (!adj[currNode].empty() && used[adj[currNode].back().second]) {
            adj[currNode].pop_back();
        }
        if (!adj[currNode].empty()) {
            auto edge = adj[currNode].back();
            int nextNode = edge.first;
            int edgeID = edge.second;
            adj[currNode].pop_back();
            used[edgeID] = 1;
            currPath.push_back(nextNode);
        }
        else {
            circuit.push_back(currPath.back());
            currPath.pop_back();
        }
    }
    reverse(circuit.begin(), circuit.end());
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
    int id = 0;
    forn(i,m)
    {
        int u,v; cin >> u >> v;
        adj[u].pb({v,id});
        adj[v].pb({u,id});
        id++;
    }

    for (int i = 0; i < n; ++i) {
        if (adj[i].size() % 2 == 1) {
            cout << "IMPOSSIBLE" << nl;
            return 0;
        }
    }

    hierholzer(n,m,1);

    if(SZ(circuit) != m+1) {cout << "IMPOSSIBLE" << nl; return 0;}

    forn(i, SZ(circuit))
    {
        cout << circuit[i] << " ";
    }
    cout << nl;
    
    return 0;
}