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

const int MAXN = 3e5 + 6;
const ll M = 1e9 + 7;

using namespace std;
 
int tests;
int D = 0;

vector<int> adj[MAXN];
bitset<MAXN> visited;
vector<int> depth(MAXN,0);
vector<vector<int>> depth_per_node(MAXN);
vector<int> parent(MAXN);

void dfs(int r, int d, int p) { // <-- pasamos la raiz como parametro
    if(visited[r]) return;
    visited[r] = 1;
    depth[r] = d;
    depth_per_node[d].pb(r);
    parent[r] = p;
    D = max(D,d);
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
        adj[0].pb(1), adj[1].pb(0);
        forn(i,n)
        {
            int l,r; cin >> l >> r;
            if(l != 0) 
            {
                adj[i+1].pb(l);
                adj[l].pb(i+1);
            }
            if(r != 0)
            {
                adj[i+1].pb(r);
                adj[r].pb(i+1);
            }
        }

        dfs(0, 0, -1);

        vector<ll> edges(n+1,0);
        dforr(i,1,D+1)
        {
            for (auto u : depth_per_node[i])
            {
                edges[u] = adj[u].size() - 1;
                for(auto v : adj[u])
                {
                    if(v != parent[u]) edges[u] += edges[v];
                }
            }
        }

        vector<ll> ans(n+1, 0);

        
        forr(i,1,D+1)
        {
            for(auto u : depth_per_node[i])
            {
                ans[u] = (ans[parent[u]] + 2*edges[u] + 1) % M;
            }
        }

        forn(i,n)
        {
            cout << ans[i+1] << " ";
        }
        cout << nl;

        forn(i,n+1)
        {
            adj[i].clear();
        }
        visited.reset();
        forn(i,D+1)
        {
            depth_per_node[i].clear();
        }
        D = 0;
    }
    
    return 0;
}