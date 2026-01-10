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

const int MAXN = 2e5 + 6;

using namespace std;
 
int tests;

bitset<MAXN> visited;
vector<int> adj[MAXN];
vector<int> depth(MAXN);
vector<int> parent(MAXN);

void dfs(int r, int d, int p) {
    if(visited[r]) return;
    visited[r] = 1;
    depth[r] = d;
    parent[r] = p;
    for(auto u:adj[r]) {
        dfs(u, d+1, r);
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
    
    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        forn(i,n-1)
        {
            int u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0,0,-1);
        // forn(i,n)
        // {
        //     cout << parent[i] << " ";
        // }
        // cout << nl;

        map<int,int> node_per_depth;
        forn(i,n)
        {
            if(node_per_depth.count(depth[i]) == 0) node_per_depth[depth[i]] = 1;
            else node_per_depth[depth[i]]++;
        }

        int mx = 0;
        for (auto [key, value] : node_per_depth) {
            mx = max(mx,value);
        }

        bool same_parent = false;
        forn(i,n)
        {
            if(node_per_depth[depth[i]] == mx)
            {
                if((int)adj[parent[i]].size() - (parent[i] == 0 ? 0 : 1) == mx) same_parent = true;
            }
        }

        cout << mx + (same_parent ? 1 : 0) << nl;

        visited.reset();
        forn(i, n) adj[i].clear();
    }
    
    return 0;
}