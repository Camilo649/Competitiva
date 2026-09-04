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

const int MAXN = 1e5+4;

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

vector<int> adj[MAXN];
int in_degree[MAXN], out_degree[MAXN];
vector<int> circuit;

void hierholzer(int start) {
    vector<int> currPath;
    currPath.push_back(start);

    while (!currPath.empty()) {
        int currNode = currPath.back();
        
        if (!adj[currNode].empty()) {
            int nextNode = adj[currNode].back();
            adj[currNode].pop_back();
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
    forn(i,m)
    {
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        out_degree[u]++;
        in_degree[v]++;
    }

    int start_node = -1, end_node = -1;
    bool bad = false;
    forn(i,MAXN)
    {
        if (out_degree[i] - in_degree[i] == 1) {
            start_node = i;
        } else if (in_degree[i] - out_degree[i] == 1) {
            end_node = i;
        } else if (in_degree[i] != out_degree[i]) {
            bad = true; // Diferencia mayor a 1, imposible
        }
    }

    if(start_node == -1 && end_node == -1) {start_node = 1; end_node = n;}

    if(bad || start_node != 1 || end_node != n) {cout << "IMPOSSIBLE" << nl; return 0;}

    hierholzer(start_node);

    if(SZ(circuit) != m+1 || circuit[0] != 1 || circuit.back() != n) {cout << "IMPOSSIBLE" << nl; return 0;}

    forn(i, SZ(circuit)) cout << circuit[i] << " ";
    cout << nl;
    
    return 0;
}