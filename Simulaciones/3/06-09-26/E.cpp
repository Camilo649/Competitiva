#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 504;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

vector<int> adj1[MAXN], adj2[MAXN], G[2*MAXN];
int adj11[MAXN][MAXN] = {}, adj22[MAXN][MAXN] = {};

vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : G[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m1,m2; cin >> n>>m1>>m2;
    if(m1 != m2) {cout << -1 << nl; return 0;}
    forn(i1,m1)
    {
        int u,v; cin >> u >> v;
        u--;v--;
        adj11[u][v] = 1;
        adj11[v][u] = 1;
    }
    forn(i2,m2)
    {
        int u,v; cin >> u >> v;
        u--;v--;
        adj22[u][v] = 1;
        adj22[v][u] = 1;
    }

    vector<pair<int,int>> edges1;
    vector<pair<int,int>> edges2;
    forn(u,n)
    {
        forn(v,n)
        {
            if(adj11[u][v] && !adj22[u][v])
            {
                adj1[u].pb(v);
                if(u>=v) continue;
                edges1.pb({u,v});
            }
        }
    }
    forn(u,n)
    {
        forn(v,n)
        {
            if(!adj11[u][v] && adj22[u][v])
            {
                adj2[u].pb(v);
                if(u>=v) continue;
                edges2.pb({u,v});
            }
        }
    }

    int m = SZ(edges1);
    //cout << m << nl;

    map<pair<int,int>, int> mapa;
    int id = 0;
    for(auto [u,v] : edges1) {mapa[{u,v}] = id; mapa[{v,u}] = id; id++;}
    id = 0;
    for(auto [u,v] : edges2) {mapa[{u,v}] = id; mapa[{v,u}] = id; id++;}


    for(auto [u,v] : edges1)
    {
        for(auto s : adj2[v])
        {
            G[mapa[{u,v}]].pb(mapa[{s,v}]);
            //G[mapa[{s,u}]].pb(mapa[{u,v}]);
        }
        for(auto s : adj2[u])
        {
            G[mapa[{v,u}]].pb(mapa[{s,u}]);
            //G[mapa[{s,u}]].pb(mapa[{v,u}]);
        }
    }

    mt.assign(id, -1);
    for (int v = 0; v < id; ++v) {
        used.assign(id, false);
        try_kuhn(v);
    }

    int ans = 0;
    forn(i,id) if(mt[i] != -1) ans++;

    // forn(v,id)
    // {
    //     print(v);
    //     for(auto u : G[v]) print(u);
    // }

    //print(m); print(ans);
    cout << ans + (m-ans)*2 << nl;

    return 0;
}