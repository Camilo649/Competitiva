#include <bits/stdc++.h>

#define fst first
#define snd second
#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define forn(i,a,b) for(int i = a; i<b; i++)
#define mset(a,v) memset(a,v,sizeof(a))
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
typedef long long ll;

const int MAXN = 1000000+5;

vector<ll> adj[MAXN];
bool vis[MAXN];
ll comp[MAXN];
ll compA = 0;

void dfs(ll nd, ll p){
    if(vis[nd]) return;
    vis[nd]=true;
    comp[nd]=compA;
    for(auto i:adj[nd]) if(i!=p){
        dfs(i,nd);
    }
}

int main(){
    ll n,m; cin>>n>>m;
    vector<ll> p(n); forn(i,0,n) cin>>p[i];
    
    ll u,v;
    forn(i,0,m){
        cin>>u>>v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    
    forn(i,0,n){
        if(!vis[i]){
            dfs(i,-1);
            compA++;
        }
        //cout<<comp[i]<<'\n';
    }
    
    vector<vector<ll>> cc(compA);
     vector<vector<ll>> cci(compA);
    forn(i,0,n) cc[comp[i]].pb(p[i]), cci[comp[i]].pb(i);
    
    forn(i,0,compA) sort(ALL(cc[i])), reverse(ALL(cc[i]));
    
    vector<ll> res(n);
    
    forn(i,0,compA){
        forn(j,0,SZ(cc[i])){
            res[cci[i][j]]=cc[i][j];
        }
    }
    
    for(auto i:res) cout<<i<<" "; cout<<'\n';
    
    
    
    
    return 0;
}