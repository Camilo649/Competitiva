#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) sort(x.begin(), x.end())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e5 + 5;

using namespace std;
 
vector<int> adj[MAXN];
bitset<MAXN> visited;
int start = -1;
int father[MAXN];
vector<int> res;

void dfs(int r, int p) {
    if (visited[r]) return;
    visited[r] = 1;
    if(start != -1) return;
    // process node r
    father[r] = p;
    for (auto u : adj[r]) {
        if(visited[u] && u != p && start == -1) {start = u; res.pb(u); res.pb(r);}
        dfs(u, r);
    }
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
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    forn(i,n)
    {
        if(!visited[i] && start == -1) dfs(i, -1);
    }
    

    if(start == -1) cout << "IMPOSSIBLE";
    else
    {
        while (res.back() != start)
        {
            res.pb(father[res.back()]);
        }
        
        cout << SZ(res) << nl
        forn(i,SZ(res))
        {
            cout << res[i]+1 << " ";
        }
    }

    cout << nl;
    
    return 0;
}