#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (int) b-1; i>= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

const int MAXN = 1e3 + 11;
const int INF  = 1e6 + 11;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << endl
#endif

vector<int> adj[MAXN];
queue<int> q;
bitset<MAXN> visited;
int dist[MAXN];

void bfs(int r){
    visited[r] = 1;
    dist[r] = 0;
    q.push(r);
    while (!q.empty())
    {
        int s = q.front(); q.pop();
        for(auto u:adj[s])
        {
            if(visited[u]) continue;
            visited[u] = 1;
            dist[u] = dist[s]+1;
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

    int w,h,n; cin >> w>>h>>n;
    vector<tuple<int,int,int>> v; 
    forn(i,n)
    {
        int x,y,s; cin >> x >> y >> s;
        v.pb({x,y,s});
    }

    forn(i,n)
    {
        forr(j,i+1,n)
        {
            int dx = get<0>(v[i]) - get<0>(v[j]);
            dx = dx*dx;
            int dy = get<1>(v[i]) - get<1>(v[j]);
            dy = dy*dy;
            int ds = get<2>(v[i]) + get<2>(v[j]);
            ds = ds*ds;

            if(dx + dy <= ds)
            {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    // Nodos especiales n y n+1
    forn(i,n)
    {
        int x = get<0>(v[i]);
        int y = get<1>(v[i]);
        int s = get<2>(v[i]);

        if(x <= s || y+s >= h)
        {
            adj[i].pb(n);
            adj[n].pb(i);
        }

        if(y <= s || x+s >= w)
        {
            adj[i].pb(n+1);
            adj[n+1].pb(i);
        }
    }

    forn(i,n+2)
    {
        dist[i] = INF;
    }

    bfs(n);

    if(dist[n+1] != INF) cout << "N";
    else cout << "S";
    cout << nl;

    return 0;
}