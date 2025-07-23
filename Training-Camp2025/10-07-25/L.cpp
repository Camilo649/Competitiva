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

const int MAXN = 400+7;
const double EPS = 1e-10;

using namespace std;
 
int tests;

queue<int> q;
bitset<MAXN> visited;
vector<int> adj[MAXN];

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m; cin >> n >> m;
    int adj[n][n] = {};
    int u,v;
    forn(i,m) 
    {
        cin >> u >> v; u--; v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    if (adj[0][n-1] == 1)
    {
        forn(i,n)
        {
            forn(j,n)
            {
                adj[i][j] = 1 - adj[i][j];
            }
        }
    }

    int distance[n];
    forn(i,n)
    {
        distance[i] = -1;
    }
    visited[0] = 1;
    distance[0] = 0;
    q.push(0);
    while(!q.empty()) {
        int s = q.front(); q.pop();
        forn(i,n) {
            if(!adj[s][i]) continue;
            if(visited[i]) continue;
            visited[i] = 1;
            distance[i] = distance[s] + 1;
            q.push(i);
        }
    }

    cout << distance[n-1] << nl;
    
    return 0;
}