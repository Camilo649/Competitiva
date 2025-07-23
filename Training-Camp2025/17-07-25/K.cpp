#include <bits/stdc++.h>

#define fst first
#define snd second
#define pb push_back
#define forn(i,a,b) for(int i = a; i< b; i++)
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset(a,v,sizeof(a))
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
typedef long long ll;

const int MAXN = 200000+5;

vector<ll> adj[MAXN];
vector<ll> nadj[MAXN];
bool vis[MAXN];
ll lvl[MAXN];

void dfs(ll nd, ll lv){
    if(vis[nd]) return;
    vis[nd]=true;
    lvl[nd]=lv;
    
    for(auto i:adj[nd]) if(!vis[i]){
        dfs(i,lv+1);
        nadj[nd].pb(i);
    }
}

int main(){
    ll n,m,k; cin>>n>>m>>k;
    
    vector<ll> ina(k); forn(i,0,k) cin>>ina[i], ina[i]--;
    
    ll u,v;
    forn(i,0,m){
        cin>>u>>v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    forn(i,0,k) adj[ina[i]].clear();
    
    
    forn(i,0,n){
        if(SZ(adj[i])>0){
            dfs(i,0);
            break;
        }
    }
    
    bool yes=true;
    forn(i,0,n) if(!vis[i]){
        yes=false;
    }
    
    if(!yes) cout<<"No\n";
    else{
        cout<<"Yes\n";
        
        ll cnt = 0;
        forn(i,0,n) if(SZ(nadj[i])>0) cnt++;
        
        cout<<cnt<<'\n';
        
        vector<pair<ll,ll>> ord; forn(i,0,n) ord.pb({lvl[i],i});
        sort(ALL(ord));
        
        forn(j,0,n){
            ll i = ord[j].snd;
            if(SZ(nadj[i])>0){
                cout<<i+1<<" "<<SZ(nadj[i])<<" ";
            }
            for(auto j:nadj[i]) cout<<j+1<<" "; cout<<'\n';
        }
    }
    
    
    
    return 0;
}