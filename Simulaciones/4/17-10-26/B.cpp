#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

const int MAXN = 2e5+4;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

vector<int> adj[MAXN];
int parent[MAXN];
bitset<MAXN> visited;
int node = -1;
int target = -1;

void dfs(int r, int p) {
    if(visited[r]) return;
    visited[r] = 1;
    parent[r] = p;
    
    for(auto u:adj[r])
    {
        //print(p+1); print(r+1); print(u+1);
        if(visited[u] && u != parent[r]) {target = r; node = u;}
        dfs(u,r);
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
    fill(parent, parent+MAXN, -1);
    map<pair<int,int>,int> edge_id;
    int id = 1;
    forn(i,m)
    {
        int u,v; cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
        edge_id[{u,v}] = id;
        edge_id[{v,u}] = id;
        id++;
    }

    dfs(0,-1);

    if(node == -1) {cout << '*';}
    else
    {
        vector<int> ans;
        int u = target, v = node;
        ans.pb(edge_id[{u,v}]);
        u = v; v = parent[v];
        //print(target); print(node);
        while (u != target && u != -1)
        {
            //print(u); print(v);
            ans.pb(edge_id[{u,v}]);
            u = v;
            v = parent[v];
        }

        cout << SZ(ans) << nl;
        forn(i,SZ(ans)) cout << ans[i] << " ";
    }
    cout << nl;

    return 0;
}