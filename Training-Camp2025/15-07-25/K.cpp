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

const int MAXN=200000+10;

ll n;
ll m;
ll s;
ll t;

bool vis[MAXN];
ll dis[MAXN];
vector<pair<ll,ll>> adj[MAXN];
ll rdis[MAXN];
bool rvis[MAXN];
vector<pair<ll,ll>> radj[MAXN];


vector<pair<ll,pair<ll,ll>>> oadj[MAXN];
vector<pair<ll,pair<ll,ll>>> roadj[MAXN];


void dijkstra(){
    priority_queue<pair<ll,ll>> pq; pq.push({0,s});
    while(!pq.empty()){
        ll nd = pq.top().snd;
        ll cost = pq.top().fst*-1;
        pq.pop();
        
        if(vis[nd]) continue;
        vis[nd]=true;
        dis[nd]=cost;
        
        for(auto i:adj[nd]){
            pq.push({ (cost+i.snd)*-1 , i.fst });
        }
    }
}

void rdijkstra(){
    priority_queue<pair<ll,ll>> pq; pq.push({0,t});
    while(!pq.empty()){
        ll nd = pq.top().snd;
        ll cost = pq.top().fst*-1;
        pq.pop();
        
        if(rvis[nd]) continue;
        rvis[nd]=true;
        rdis[nd]=cost;
        
        for(auto i:radj[nd]){
            pq.push({ (cost+i.snd)*-1 , i.fst });
        }
    }
}

bool bridge[MAXN];
bool visL[MAXN];
ll cntLvl[MAXN];
ll lvl[MAXN];
ll down[MAXN];

void dfss(ll nd, ll lv, ll ind){
    if(visL[nd]) return;
    visL[nd]=true;
    lvl[nd]=lv;
    down[nd]=lv+1;
    //cout<<">>>>"<<nd<<" "<<down[nd]<<" "<<lvl[nd]<<'\n';
    for(auto i:roadj[nd]) if(i.fst!=ind){
        if(!visL[i.snd.fst]) dfss(i.snd.fst,lv+1,i.fst), down[nd] = min(down[nd], down[i.snd.fst]);
        else{
            down[nd] = min(down[nd], lvl[i.snd.fst]);
        }
        
        if(down[i.snd.fst]>lvl[nd]) bridge[i.fst]=true;
    }
    
    //cout<<"<<<<"<<nd<<" "<<down[nd]<<" "<<lvl[nd]<<'\n';
}



int main(){ FIN;

    cin>>n>>m>>s>>t; s--; t--;
    
    vector<pair<ll,pair<ll,ll>>> ed;
    ll u,v,c;
    forn(i,0,m){
        cin>>u>>v>>c; u--; v--;
        adj[u].pb({v,c});
        radj[v].pb({u,c});
        ed.pb({c,{u,v}});
    }
    
    dijkstra();
    rdijkstra();
    
    forn(i,0,m){
        if(!vis[ed[i].snd.fst] || !rvis[ed[i].snd.snd]) continue;
        if(dis[ed[i].snd.fst]+ ed[i].fst + rdis[ed[i].snd.snd] == dis[t]){
            u=ed[i].snd.fst;
            v=ed[i].snd.snd;
            c=ed[i].fst;
            oadj[u].pb({i,{v,c}});
            roadj[v].pb({i,{u,c}});
            roadj[u].pb({i,{v,c}});
        }

    }
    
    //dfs(s,0);
    mset(visL,false);
    dfss(s,0,m+5);
    


    forn(i,0,m){
        if(!vis[ed[i].snd.fst] || !rvis[ed[i].snd.snd]){
            cout<<"NO\n";
            continue;
        }
        
        if(bridge[i]) cout<<"YES\n";
        else{
            ll dist = dis[ed[i].snd.fst]+ ed[i].fst + rdis[ed[i].snd.snd];
            if((dist-dis[t])+1>=ed[i].fst){
                cout<<"NO\n";
            }else{
                cout<<"CAN "<<(dist-dis[t])+1<<'\n';
            }
        }
        
    }
    return 0;
}