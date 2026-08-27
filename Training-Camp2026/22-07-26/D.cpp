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
#define GE
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 2e5 + 6;

using namespace std;

int maxcolor = 0;
queue<int> q;
bitset<MAXN> visited;
int color[MAXN];
int father[MAXN];
vector<int> adj[MAXN];

void bfs(int r) { // <-- pasamos la raiz como parametro
    visited[r] = 1;
    q.push(r);
    while(!q.empty()) {
        int s = q.front(); q.pop();

        set<int> forbidden;
        forbidden.insert(color[s]);
        if(father[s] != -1) 
        {
            forbidden.insert(color[father[s]]);
        }

        int c = 1;
        for (auto u:adj[s])
        {
            if(color[u] == 0)
            {
                while (c<=maxcolor && forbidden.count(c) == 1)
                {
                    c++;
                }
                color[u] = c;
                forbidden.insert(c);
            }
        }

        for (auto u:adj[s]) {
            if(visited[u]) continue;
            visited[u] = 1;
            father[u] = s;
            q.push(u);
        }
    }
}

int main()
{
    #ifdef GE
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    forn(i,n-1) {
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }

    // forn(i,n)
    // {
    //     forn(j,adj[i].size())
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << nl;
    // }

    forn(i,n)
    {
        maxcolor = max(maxcolor, (int)adj[i].size());
    }

    maxcolor++;
    cout << maxcolor << nl;

    father[0] = -1;
    color[0] = 1;
    bfs(0);

    forn(i,n)
    {
        cout << color[i] << " ";
    }
    cout << nl;

    return 0;
}