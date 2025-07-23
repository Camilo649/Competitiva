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

const int MAXN = 200000+5;

using namespace std;
 
vector<pair<ll, ll>> adj[MAXN];
 
queue<int> q;
bitset<MAXN> visited;
int distance[MAXN];
vector<ll> sec;

void bfs(ll r) { // <-- pasamos la raiz como parametro
    visited[r] = 1;
    q.push(r);
    while(!q.empty()) {
        int s = q.front(); q.pop();
        sec.pb(s);
        for (auto u:adj[s]) {
            if(visited[u.second]) continue;
            visited[u.second] = 1;
            q.push(u.second);
        }
    }
}

int main()
{
    // #ifdef MILF
    //     freopen("../input.txt", "r", stdin);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n; cin >> n;
    vector<pair<ll, ll>> edges(n-1);
    forn(i,n-1){
        cin >> edges[i].first >> edges[i].second;
    }

    ll ind[MAXN];
    vector<ll> op(n); 
    forn(i,n) {
        cin >> op[i];
        ind[op[i]-1] = i;
    }

    forn(i,n-1){
        adj[edges[i].first-1].pb({ind[edges[i].second-1], edges[i].second-1});
        adj[edges[i].second-1].pb({ind[edges[i].first-1], edges[i].first-1});
    }

    forn(i,n)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    bfs(0);

    bool res = true;
    forn(i,n) if(sec[i]!=op[i]-1) res=false;
    if(res) cout<<"Yes\n";
    else cout<<"No\n";
    
    return 0;
}