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

const int MAXN = 100;
const int INF  = 1e9;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << endl
#endif

int n;
int a[MAXN][MAXN];
vector<pair<int,int>> adj[MAXN*MAXN + 2];
int parent[MAXN*MAXN + 2];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
bitset<MAXN*MAXN + 2> visited;
int dist[MAXN*MAXN + 2];

void dijkstra(int r){
    fill(dist, dist+MAXN*MAXN+2, INF);
    pq.push({1,r});
    dist[r] = 1;
    while (!pq.empty())
    {
        int v = pq.top().snd; pq.pop();
        if(visited[v]) continue;
        visited[v] = 1;
        for(auto [u,w] : adj[v])
        {
            if(-abs(dist[v]*w) < dist[u])
            {
                print(v);
                print(dist[v]*w);
                dist[u] = -abs(dist[v]*w);
                parent[u] = v;
                pq.push({dist[u], u});
            }
        }
    }
}

void built_graph(int r, set<int> hist)
{
    if(r > n*(n-1)) return;

    //print(r);
    forr(i,1,n+1)
    {
        if(hist.count(i) == 0)
        {
            set<int> s = hist;
            s.insert(i);
            adj[r].pb({((r+n-1)/n)*n + i, -a[i-1][((r+n-1)/n)]});
            adj[((r+n-1)/n)*n + i].pb({r, -a[i-1][((r+n-1)/n)]});
            //print(i); print(-a[i-1][((r+n-1)/n)]);
            built_graph(((r+n-1)/n)*n  + i, s);
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

    cin >> n;
    forn(i,n)
    {
        forn(j,n)
        {
            cin >> a[i][j];
        }
    }

    // Fantasma1 = 0
    forn(i,n)
    {
        adj[0].pb({i+1,-a[i][0]});
        adj[i+1].pb({0,-a[i][0]});
    }
    // Fantasma2 = n*n + 1
    forn(i,n)
    {
        adj[n*n+1].pb({n*n-n + i + 1, -1});
        adj[n*n-n + i + 1].pb({n*n+1, -1});
    }

    forr(i,1,n+1)
    {
        set<int> s; s.insert(i);
        built_graph(i,s);
    }

    // forn(i,n*n+2)
    // {
    //     cout << "i: " << i << nl;
    //     for(auto node : adj[i])
    //     {
    //         cout << node.fst << " " << node.snd << nl;
    //     }
    //     cout << nl;
    // }

    dijkstra(0);

    int nd = n*n+1;
    
    vector<int> camino;

    forn(i,n*n+2){
        cout<<dist[i]<<nl;
    }
    
    forn(i,n)
    {
        nd = parent[nd];
        camino.pb(nd);
    }

    reverse(ALL(camino));

    forn(i,n){
        cout<<camino[i]<<" ";
    }
    cout<<nl;


    return 0;
}