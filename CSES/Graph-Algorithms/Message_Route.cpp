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

const int MAXN = 1e5 + 2;

using namespace std;
 
vector<int> adj[MAXN];
queue<int> q;
bitset<MAXN> visited;
int dist[MAXN];
int father[MAXN];

void bfs(int r, int p) {
    visited[r] = 1;
    dist[r] = 0;
    father[r] = p;
    q.push(r);
    while(!q.empty()) {
        int s = q.front(); q.pop();
        // process node
        for (auto u:adj[s]) {
            if(visited[u]) continue;
            visited[u] = 1;
            dist[u] = dist[s] + 1;
            q.push(u);
            father[u] = s;
        }
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
        int u,v; cin >> u >> v; u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }

    memset(dist, -1, sizeof(dist));
    bfs(0,-1);

    if(dist[n-1] == -1) cout << "IMPOSSIBLE";
    else
    {
        vector<int> res; res.pb(n-1);
        while (res.back() != 0)
        {
            res.pb(father[res.back()]);
        }

        cout << SZ(res) << nl
        dforn(i,SZ(res))
        {
            cout << res[i]+1 << " ";
        }
    }
    cout << nl
    
    return 0;
}