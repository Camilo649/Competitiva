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

const int MAXN = 1e5 + 3;

using namespace std;
 
int tests;

vector<int> adj[MAXN];
queue<int> q;
bitset<MAXN> visited;
vector<int> res;
bitset<MAXN> dams;

void bfs(int r) {
    visited[r] = 1;
    q.push(r);
    while(!q.empty()) {
        int s = q.front(); q.pop();
        if(dams[s]) res.pb(s);
        for (auto u:adj[s]) {
            if(visited[u]) continue;
            visited[u] = 1;
            q.push(u);
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
    
    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        forr(i,1,n)
        {
            int p; cin >> p; p--;
            adj[p].pb(i); adj[i].pb(p);
        }
        int m; cin >> m;
        forn(j,m)
        {
            int a; cin >> a; a--;
            dams[a] = 1;
        }

        bfs(0);

        cout << SZ(res)-1 << " ";
        forr(i,1,SZ(res))
        {
            cout << res[i]+1 << " ";
        }
        cout << nl;

        forn(i,n) adj[i].clear();
        visited.reset();
        res.clear();
        dams.reset();
    }
    
    return 0;
}