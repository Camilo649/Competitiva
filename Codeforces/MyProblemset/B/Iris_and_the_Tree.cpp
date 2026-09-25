#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((ll) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 2e5+4;

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
bitset<MAXN> visited;
int deepth[MAXN] = {};

void dfs(int r, int d) { // <-- pasamos la raiz como parametro
    if(visited[r]) return;
    //print(r); print(d);
    visited[r] = 1;
    deepth[r] = d;
    for(auto u:adj[r]) {
        dfs(u, d+1);
    }
}

int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;
    
    while (tests--)
    {
        ll n,W; cin >> n >> W;
        int p[n]; forn(i,n-1) {cin >> p[i+1]; p[i+1]--;}
        p[0] = 0;
        forn(i,n-1)
        {
            adj[i+1].pb(p[i+1]);
            adj[p[i+1]].pb(i+1);
        }
        dfs(0,0);
        // forn(i,n) cout << deepth[i] << " ";
        // cout << nl;

        int path_to_size[n] = {};
        map<int,vector<int>> node_to_paths;
        forn(i,n)
        {
            int a = i, b = (i+1)%n;
            int d = min(deepth[a], deepth[b]);
            //print(a); print(b); print(d);
            while(deepth[a] != d)
            {
                path_to_size[i]++;
                node_to_paths[a].pb(i);
                a = p[a];
            }
            while(deepth[b] != d)
            {
                path_to_size[i]++;
                node_to_paths[b].pb(i);
                b = p[b];
                //print(b);
            }

            while (a!=b)
            {
                path_to_size[i]++;
                node_to_paths[a].pb(i);
                path_to_size[i]++;
                node_to_paths[b].pb(i);
                a = p[a];
                b = p[b];
            }
        }

        // forn(i,n) cout << path_to_size[i] << " ";
        // cout << nl;
        
        ll c = n;
        ll w = 0;
        ll fixed = 0;
        forn(i,n-1)
        {
            ll x,t; cin >> x >> t;
            x--;
            w += t;
            fixed += SZ(node_to_paths[x])*t;
            for(auto pat_idx : node_to_paths[x])
            {
                path_to_size[pat_idx]--;
                if(path_to_size[pat_idx] == 0) c--;
            }

            //print(fixed); print(c); print(w);
            cout << fixed + c*(W-w) << " ";
        }
        cout << nl;

        visited.reset();
        forn(i,n) adj[i].clear();
    }
    
    return 0;
}