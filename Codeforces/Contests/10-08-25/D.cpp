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

const int MAXN = 2e5 + 7;

using namespace std;
 
int tests;

vector<int> adj[MAXN];
bitset<MAXN> visited;
bitset<MAXN> leaf;

void dfs(int r) {
    if(visited[r]) return;
    visited[r] = 1;
    if(adj[r].size() == 1) leaf[r] = 1;
    for(auto u:adj[r]) {
        dfs(u);
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
        int res = 1e9;
        int n; cin >> n;
        forn(i,n) adj[i].clear();
        visited.reset();
        leaf.reset();
        forn(i,n-1)
        {
            int u,v; cin >> u >> v;
            u--; v--;
            adj[u].pb(v); adj[v].pb(u);
        }

        if (n>2)
        {
            dfs(0);
            int L = leaf.count();
            int leaf_neigh[n] = {};
            forn(i,n)
            {
                for(auto u : adj[i])
                {
                    if(leaf[u]) leaf_neigh[i]++;
                }
            }
            forn(i,n)
            {
                res = min(res,L - leaf_neigh[i] - leaf[i]);
            }
        }
        else
        {
            res = 0;
        }

        cout << res << nl;
    }
    
    return 0;
}