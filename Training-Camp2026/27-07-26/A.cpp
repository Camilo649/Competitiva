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

const int MAXN = 50 + 1;
const int INF = 1e6;

using namespace std;

bitset<MAXN> visited;
vector<ll> adj[MAXN];
ll nodes = 0;

void dfs(int r) { // <-- pasamos la raiz como parametro
    if(visited[r]) return;
    visited[r] = 1;
    nodes++;
    // process node r
    for(auto u:adj[r]) {
        dfs(u);
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

    ll n,m; cin >> n >> m;
    forn(i,m)
    {
        ll u,v;
        cin >> u >> v;
        u--; v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll res = 1;
    forn(i,n)
    {
        if(!visited[i])
        {
            nodes = 0;
            dfs(i);
            res *= (ll)1 << (nodes-1);
        }
    }

    cout << res << nl;

    return 0;
}