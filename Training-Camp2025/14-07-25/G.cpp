#include <bits/stdc++.h>

#define fst first
#define snd second
#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define forn(i,a,b) for(int i = a; i<b; i++)
#define mset(a,v) memset(a,v,sizeof(a))
//#define FIN ios::sync_

using namespace std;
typedef long long ll;

const int MAXN = 200000+5;

vector<ll> adj[MAXN];
ll cat[MAXN];
ll pa[MAXN];
ll k;

void dfs(ll nd, ll p){
    pa[nd]=p;
    for(auto i:adj[nd]) if(i!=p){
        dfs(i,nd);
    }
}

void extend(ll nd, ll p){
    
    if(p!=-1 && cat[p]!=0){
        if(cat[p]>k){
            cat[nd]=cat[p];
        }else{
            if(cat[nd]>0){
                cat[nd]+=cat[p];
            }
        }
    }
    
    for(auto i:adj[nd]) if(i!=p){
        extend(i,nd);
    }
}

int main(){
    ll n; cin>>n>>k;
    
    forn(i,0,n) cin>>cat[i];
    
    ll u,v;
    forn(i,0,n-1) cin>>u>>v, u--, v--, adj[u].pb(v), adj[v].pb(u);
    
    dfs(0,-1);
    extend(0,-1);
    
    ll cnt = 0;
    ll res = 0;
    forn(i,1,n){
        if(SZ(adj[i])==1){
            if(cat[i]>k) res++;//, cout<<i<<" "<<cat[i]<<"\n";
            cnt++;
        }
    }
    
    cout<<cnt-res<<'\n';
    
    return 0;
}