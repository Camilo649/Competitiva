#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((int) x.len())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 2e5 + 4;

using namespace std;
 
int tests;

vector<int> adj[MAXN];
vector<int> color(MAXN, -1);

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
        int n,m; cin >> n >> m;

        forn(i,m)
        {
            int u,v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        forn(i, n) {
            if(color[i] != -1) continue; // ya visitado
        
            // nueva componente, BFS desde i
            bool es_bipartito = true;
            int count0 = 0, count1 = 0;
        
            queue<int> q;
            color[i] = 0;
            q.push(i);
        
            while(!q.empty()) {
                int v = q.front(); q.pop();
                if(color[v] == 0) count0++;
                else count1++;
            
                for(int u : adj[v]) {
                    if(color[u] == -1) {
                        color[u] = 1 - color[v];
                        q.push(u);
                    } else if(color[u] == color[v]) {
                        es_bipartito = false;
                    }
                }
            }
        
            if(es_bipartito) ans += max(count0, count1);
        }

        cout << ans << nl;

        forn(i,n) adj[i].clear();
        forn(i,n) color[i] = -1;
    }
    
    return 0;
}