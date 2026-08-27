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

const int MAXN = 1<<16;

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

int get_node_id(char c1, char c2) {
    return c1 * 256 + c2;
}

string get_node_str(int id) {
    string s;
    s += (char)(id / 256);
    s += (char)(id % 256);
    return s;
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
    
    int n; cin >> n;
    int first = -1;
    forn(i,n)
    {
        string t; cin >> t;
        // El string "abc" es una arista del nodo "ab" al nodo "bc"
        int u = get_node_id(t[0], t[1]);
        int v = get_node_id(t[1], t[2]);
        adj[u].push_back(v);
        out_degree[u]++;
        in_degree[v]++;
        if (first == -1) first = u;
    }

    int start_node = -1;
    int start_count = 0, end_count = 0;
    bool bad = false;
    forn(i,MAXN)
    {
        if (out_degree[i] - in_degree[i] == 1) {
            start_node = i;
            start_count++;
        } else if (in_degree[i] - out_degree[i] == 1) {
            end_count++;
        } else if (in_degree[i] != out_degree[i]) {
            bad = true; // Diferencia mayor a 1, imposible
        }
    }

    if (bad || start_count > 1 || end_count > 1) {cout << "NO" << nl; return 0;}

    if(start_node == -1) start_node = first;

    hierholzer(start_node);

    if(SZ(circuit) != n+1) {cout << "NO" << nl; return 0;}

    string ans = get_node_str(circuit[0]);
    forr(i,1,SZ(circuit))
    {   
        string t = get_node_str(circuit[i]);
        ans += t[1];
    }

    cout << "YES" << nl;
    cout << ans << nl;

    return 0;
}