#include <bits/stdc++.h>

#define forr(i,a,b) for(int  i = (int) a; i < (int) b; ++i)
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

const int MAXN = 1e5+3;
const int INF = 1e9+10;

using namespace std;

int n,m;

vector<pair<ll,ll>> adj[MAXN];

ll dist[MAXN];

void dijkstra(int r){
    priority_queue<pair<ll,int>> pq;
    fill(dist,dist+MAXN,INF);
    bitset<MAXN> visited;
    pq.push({0,r});
    dist[r] = 0;

    while (!pq.empty())
    {
        int v = pq.top().second; pq.pop();

        if(visited[v]) continue;
            visited[v] = 1;
        for (auto [u,w] : adj[v])
        {
            if(abs(dist[v])+w < dist[u]){
                dist[u] = abs(dist[v])+w;
                pq.push({-dist[u],u});
            }
        }
    }
}


vector<pair<ll,ll>> adj1[MAXN];

ll distSG[MAXN];

void dijkstra2(int r){
    priority_queue<pair<ll,int>> pq;
    fill(distSG,distSG+MAXN,INF);
    bitset<MAXN> visited;
    pq.push({0,r});
    distSG[r] = 0;

    while (!pq.empty())
    {
        int v = pq.top().second; pq.pop();

        if(visited[v]) continue;
            visited[v] = 1;
        for (auto [u,w] : adj1[v])
        {
            if(abs(distSG[v])+w < distSG[u]){
                distSG[u] = abs(distSG[v])+w;
                pq.push({-distSG[u],u});
            }
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

    cin>>n>>m;

    int P,G; cin>>P>>G;P--;G--;

    forn(i,m){
        int u,v,w; cin>>u>>v>>w;u--;v--;
        adj[u].pb({v,w});
        adj[v].pb({u,w});        
    }

    dijkstra(P);
    ll distP[MAXN];
    ll distG[MAXN];

    forn(i,n){
        distP[i] = dist[i];
    }
    dijkstra(G);
    forn(i,n){
       distG[i] = dist[i];
    }

    forn(i,MAXN){
        if(i!= G){
            for(auto [u,w] : adj[i]){
                if(u!= G){
                    adj1[i].pb({u,w});
                    adj1[u].pb({i,w});
                }
            }
        }
    }
    dijkstra2(P);

    bool flag = true;

    forn(i,n){
        if(distP[G] == distG[i] && distSG[i] > distP[G]*2 && i!= P && i != G){
            cout<<i+1<<" ";
            flag = 0;
        }
    }
    if(flag){
        cout<<'*';
    }
  cout<<nl;

  return 0;
}