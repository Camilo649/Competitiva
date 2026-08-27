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

const int MAXN = 2e3 + 8;

using namespace std;

// Debugging
#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

template<typename S, typename T> ostream& operator<<(ostream& os, const pair<S, T>& p) {
    return os << (DBG ? "(" : "") << p.fst << (DBG ? ", " : " ") << p.snd << (DBG ? ")" : "");
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    if (DBG) os << "[";
    for (auto& x : v) os << x << (DBG ? ", " : " ");
    return DBG ? os << "]" : os;
}

vector<pair<int,int>> adj[MAXN]; // 0..n-1 -> filas | n..n+m-1 -> columnas
bitset<MAXN*MAXN> used;
vector<int> circuit;
void hierholzer(int n, int start) {
    // for (int i = 0; i < n; ++i) {
    //     if (adj[i].size() % 2 == 1) {
    //         return;
    //     }
    // }

    vector<pair<int, int>> currPath;      // {nodo_actual, id_arista}
    currPath.push_back({start,-1});

    while (!currPath.empty()) {
        int currNode = currPath.back().fst;
        while (!adj[currNode].empty() && used[adj[currNode].back().snd]) {
            adj[currNode].pop_back();
        }
        if (!adj[currNode].empty()) {
            auto nextEdge = adj[currNode].back();
            adj[currNode].pop_back();
            used[nextEdge.snd] = 1;
            currPath.pb(nextEdge);
        }
        else {
            int id = currPath.back().snd;
            if (id != -1) {
                circuit.pb(id);
            }
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
    int a[n][m];
    int id = 1;
    unordered_map<int, pair<int,int>> coords;
    forn(i,n)
    {
        forn(j,m)
        {
            char c; cin >> c;
            if(c == '.')
            {
                a[i][j] = -1;
                adj[i].pb({n+j, id});
                adj[n+j].pb({i, id});
                coords[id] = {i,j};
                id++;
            }
            else a[i][j] = 0;
        }
    }

    int grados_impares = 0;
    int start = -1;
    forn(node,n+m)
    {
        if(SZ(adj[node])%2 == 1) 
        {
            grados_impares++;
            start = node;
        }
    }

    if(grados_impares != 0 && grados_impares != 2) {cout << '*' << nl; return 0;}
    
    if (start == -1) {
        forn(node, n + m) {
            if (!adj[node].empty()) {start = node; break;}
        }
    }

    hierholzer(n+m, start);

    if(SZ(circuit) != id-1) {cout << '*' << nl; return 0;}

    int step = 1;
    for(int e : circuit)
    {
        int i = coords[e].fst;
        int j = coords[e].snd;
        a[i][j] = step;
        step++;
    }

    forn(i,n)
    {
        forn(j,m)
        {
            cout << a[i][j] << " ";
        }
        cout << nl;
    }

    return 0;
}