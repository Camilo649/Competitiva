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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 2e5 + 8;

using namespace std;

vector<int> dp[MAXN];
int parent[MAXN];

queue<int> q;
bitset<MAXN> visited;
int dist1[MAXN];
vector<pair<int,char>> adj[MAXN];

void bfs1(int r) { // <-- pasamos la raiz como parametro
    visited[r] = 1;
    dist1[r] = 0;
    q.push(r);
    while(!q.empty()) {
        int s = q.front(); q.pop();
        // process node s
        for (auto u:adj[s]) {
            if(visited[u.fst]) continue;
            visited[u.fst] = 1;
            dist1[u.fst] = dist1[s] + 1;
            q.push(u.fst);
        }
    }
}

int distN[MAXN];
void bfsN(int r) { // <-- pasamos la raiz como parametro
    visited[r] = 1;
    distN[r] = 0;
    q.push(r);
    while(!q.empty()) {
        int s = q.front(); q.pop();
        // process node s
        for (auto u:adj[s]) {
            if(visited[u.fst]) continue;
            visited[u.fst] = 1;
            distN[u.fst] = distN[s] + 1;
            q.push(u.fst);
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
        int v,u;
        char c;
        cin >> v >> u >> c;
        v--; u--;
        adj[v].pb({u,c});
        adj[u].pb({v,c});
    }

    bfs1(0);
    visited.reset();
    bfsN(n-1);

    int D = dist1[n-1];
    string path;
    forn(i,D) path += 'z';
    dp[0].pb(0);
    bitset<MAXN> added;
    added[0] = 1;
    forr(i,1,D+1)
    {
        for(auto v : dp[i-1])
        {
            for(auto p : adj[v])
            {
                int u = p.fst;
                if(dist1[u] != dist1[v] + 1 || dist1[u] + distN[u] != D) continue;
                path[i-1] = min(path[i-1], p.snd);
            }
        }

        for(auto v : dp[i-1])
        {
            for(auto p : adj[v])
            {
                int u = p.fst;
                char c = p.snd;
                if(dist1[u] != dist1[v] + 1 || dist1[u] + distN[u] != D || c != path[i-1] || added[u]) continue;
                dp[i].pb(u); added[u] = 1; parent[u] = v;
            }
        }
    }

    cout << D << nl;
    vector<int> node; node.pb(n-1);
    forn(i,D)
    {
        node.pb(parent[node.back()]);
    }
    dforn(i,D+1)
    {
        cout << node[i]+1 << " ";
    }
    cout << nl;
    cout << path << nl;

    return 0;
}