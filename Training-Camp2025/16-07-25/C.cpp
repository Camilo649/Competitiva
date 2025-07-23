#include <bits/stdc++.h>

#define fst first
#define snd second
#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset(a,v,sizeof(a))
#define forn(i,a,b) for(int i= a; i< b; i++)
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

const int MAXN = 200000+5;

vector<pair<ll,ll>> adj[MAXN];
bool vis[MAXN];
ll lvl[MAXN];
ll down[MAXN];
bool bri[MAXN];


void dfs(ll nd, ll p, ll lv){
    if(vis[nd]) return;
    vis[nd]=true;
    lvl[nd]=lv;
    down[nd]=lvl[nd]+1;

    for(auto i:adj[nd]) if(i.fst!=p){
        if(!vis[i.fst]) dfs(i.fst,nd,lv+1);
        else down[nd]=min(down[nd],lvl[i.fst]);
        down[nd]=min(down[nd],down[i.fst]);

        if(down[i.fst]>lvl[nd]){
          bri[i.snd]=true;
        } 
    }
}

vector<ll> comp[MAXN];
ll myComp[MAXN];
ll compA;

void cosa(ll nd, ll p){
    if(vis[nd]) return;
    vis[nd]=true;
    comp[compA].pb(nd);
    myComp[nd]=compA;
    for(auto i:adj[nd]) if(!bri[i.snd]){
        cosa(i.fst,nd);
    }
}

vector<ll> nadj[MAXN];
ll cnt[MAXN];

void ddfs(ll nd, ll p){
    if(vis[nd]) return;
    vis[nd]=true;
    cnt[nd]=SZ(comp[nd]);
    for(auto i:nadj[nd]) if(i!=p && !vis[i]){
        ddfs(i,nd);
        cnt[nd]+=cnt[i];
    }
    //cout<<nd<<" "<<cnt[nd]<<'\n';
} 

ll maxi = 0;
void dddfs(ll nd, ll p){
    if(vis[nd]) return;
    vis[nd]=true;
    if(p!=-1) maxi=max(maxi,cnt[nd]*(cnt[0]-cnt[nd]));
    for(auto i:nadj[nd]) if(i!=p && !vis[i]){
        dddfs(i,nd);
    }
}

int main(){ FIN;
    ll t; cin>>t;
    while(t--){
        ll n,m; cin>>n>>m;
        
        forn(i,0,n) adj[i].clear(), vis[i]=false;
        forn(i,0,m) bri[i]=false;
        
        ll u,v;
        forn(i,0,m){
            cin>>u>>v; u--; v--;
            adj[u].pb({v,i});
            adj[v].pb({u,i});
        }
        
        dfs(0,-1,0);
        
        forn(i,0,n) comp[i].clear(), vis[i]=false;
        compA=0;
        forn(i,0,n){
            if(!vis[i]) cosa(i,-1), compA++;
        }
        
        //cout<<compA<<'\n';
        
        forn(i,0,n) nadj[i].clear();
        forn(i,0,n){
            for(auto j:adj[i]) if(bri[j.snd]){ nadj[myComp[i]].pb(myComp[j.fst]); nadj[myComp[j.fst]].pb(myComp[i]); }
        }
        
        maxi=0;
        
        forn(i,0,n) vis[i]=false;
        ddfs(0,-1);
        
        forn(i,0,n) vis[i]=false;
        dddfs(0,-1);
    
        //cout<<maxi<<'\n';
        cout<<(n*(n-1))/2-maxi<<'\n';
       
        
    }
    return 0;
}