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

const int MAXN = 2000+5;

bool vis[MAXN][MAXN];
ll dX[MAXN][MAXN];
ll dY[MAXN][MAXN];
string ma[MAXN];

vector<pair<ll,ll>> operL = {{1,0},{-1,0},{0,-1}};
vector<pair<ll,ll>> operR = {{1,0},{-1,0},{0,1}};

ll n,m; 

void left(){
    priority_queue<pair<pair<ll,ll>,pair<ll,ll>>> colaL; 
    forn(i,0,n){
        forn(j,0,m){
            if(vis[i][j]){
                for(auto o:operL){
                    if(i+o.fst<0 || i+o.fst>=n) continue;
                    if(j+o.snd<0 || j+o.snd>=m) continue;
                    if(o.snd==0) colaL.push({{ (dX[i][j]+(o.snd<0?abs(o.snd):0))*-1 , (dY[i][j]+(o.snd>0?abs(o.snd):0))*-1 },{i+o.fst,j+o.snd}});
                    else colaL.push({{ (dX[i][j]+(o.snd<0?abs(o.snd):0))*-1 , (dY[i][j]+(o.snd>0?abs(o.snd):0))*-1  },{i+o.fst,j+o.snd}});
                }
            }
        }
    }
    
    priority_queue<pair<pair<ll,ll>,pair<ll,ll>>> colaR; 
    forn(i,0,n){
        forn(j,0,m){
            if(vis[i][j]){
                for(auto o:operR){
                    if(i+o.fst<0 || i+o.fst>=n) continue;
                    if(j+o.snd<0 || j+o.snd>=m) continue;
                    if(o.snd==0) colaR.push({{ (dY[i][j]+(o.snd>0?abs(o.snd):0))*-1 , (dX[i][j]+(o.snd<0?abs(o.snd):0))*-1 },{i+o.fst,j+o.snd}});
                    else colaR.push({{ (dY[i][j]+(o.snd>0?abs(o.snd):0))*-1 , (dX[i][j]+(o.snd<0?abs(o.snd):0))*-1 },{i+o.fst,j+o.snd}});
                }
            }
        }
    }
    while(!colaL.empty()||!colaR.empty()){
    while(!colaL.empty()){
        ll ii = colaL.top().snd.fst;
        ll jj = colaL.top().snd.snd;
        ll dxx = colaL.top().fst.fst*-1;
        ll dyy = colaL.top().fst.snd*-1;
        
        colaL.pop();
        
        
            if(ma[ii][jj]=='*') continue;
            if(vis[ii][jj]){
                continue;
            }
            
        
        vis[ii][jj]=true;
        //ma[ii][jj]='+';
        dX[ii][jj]=dxx;
        dY[ii][jj]=dyy;
        
        for(auto o:operL){
            if(ii+o.fst<0 || ii+o.fst>=n) continue;
            if(jj+o.snd<0 || jj+o.snd>=m) continue;
            if(vis[ii+o.fst][jj+o.snd]) continue;
            if(ma[ii+o.fst][jj+o.snd] == '*') continue;
            //cola.push({{dxx+(o.fst<0?abs(o.fst),0),dyy+(o.fst>0?abs(o.fst),0)},{ii+o.fst,jj+o.snd}});
            if(o.snd==0) colaL.push({{ (dxx+(o.snd<0?abs(o.snd):0))*-1 , (dyy+(o.snd>0?abs(o.snd):0))*-1 },{ii+o.fst,jj+o.snd}});
            else colaL.push({{(dxx+(o.snd<0?abs(o.snd):0))*-1 , (dyy+(o.snd>0?abs(o.snd):0))*-1},{ii+o.fst,jj+o.snd}});
        }
        
        for(auto o:operR){
            if(ii+o.fst<0 || ii+o.fst>=n) continue;
            if(jj+o.snd<0 || jj+o.snd>=m) continue;
            if(vis[ii+o.fst][jj+o.snd]) continue;
            if(ma[ii+o.fst][jj+o.snd] == '*') continue;
            //cola.push({{dxx+(o.fst<0?abs(o.fst),0),dyy+(o.fst>0?abs(o.fst),0)},{ii+o.fst,jj+o.snd}});
            if(o.snd==0) colaR.push({{ (dyy+(o.snd>0?abs(o.snd):0))*-1 , (dxx+(o.snd<0?abs(o.snd):0))*-1 },{ii+o.fst,jj+o.snd}});
            else colaR.push({{ (dyy+(o.snd>0?abs(o.snd):0))*-1 , (dxx+(o.snd<0?abs(o.snd):0))*-1 },{ii+o.fst,jj+o.snd}});
        }
    }
    
    while(!colaR.empty()){
        ll ii = colaR.top().snd.fst;
        ll jj = colaR.top().snd.snd;
        ll dxx = colaR.top().fst.snd*-1;
        ll dyy = colaR.top().fst.fst*-1;
        
        colaR.pop();
        
        
            if(ma[ii][jj]=='*') continue;
            if(vis[ii][jj]){
               continue;
            }
            
        
        vis[ii][jj]=true;
        //ma[ii][jj]='+';
        dX[ii][jj]=dxx;
        dY[ii][jj]=dyy;
        
        for(auto o:operR){
            if(ii+o.fst<0 || ii+o.fst>=n) continue;
            if(jj+o.snd<0 || jj+o.snd>=m) continue;
            if(vis[ii+o.fst][jj+o.snd]) continue;
            if(ma[ii+o.fst][jj+o.snd] == '*') continue;
            //cola.push({{dxx+(o.fst<0?abs(o.fst),0),dyy+(o.fst>0?abs(o.fst),0)},{ii+o.fst,jj+o.snd}});
            if(o.snd==0) colaL.push({{(dxx+(o.snd<0?abs(o.snd):0))*-1 , (dyy+(o.snd>0?abs(o.snd):0))*-1},{ii+o.fst,jj+o.snd}});
            else colaL.push({{(dxx+(o.snd<0?abs(o.snd):0))*-1 , (dyy+(o.snd>0?abs(o.snd):0))*-1},{ii+o.fst,jj+o.snd}});
        }
        
        for(auto o:operL){
            if(ii+o.fst<0 || ii+o.fst>=n) continue;
            if(jj+o.snd<0 || jj+o.snd>=m) continue;
            if(vis[ii+o.fst][jj+o.snd]) continue;
            if(ma[ii+o.fst][jj+o.snd] == '*') continue;
            //cola.push({{dxx+(o.fst<0?abs(o.fst),0),dyy+(o.fst>0?abs(o.fst),0)},{ii+o.fst,jj+o.snd}});
            if(o.snd==0) colaR.push({{(dyy+(o.snd>0?abs(o.snd):0))*-1 , (dxx+(o.snd<0?abs(o.snd):0))*-1 },{ii+o.fst,jj+o.snd}});
            else colaR.push({{ (dyy+(o.snd>0?abs(o.snd):0))*-1 , (dxx+(o.snd<0?abs(o.snd):0))*-1 },{ii+o.fst,jj+o.snd}});
        }
    }
    }
}

int main(){ FIN;
    ll r,c,x,y; cin>>n>>m>>r>>c>>x>>y; // x = left, y = right
    r--; c--;
    
    forn(i,0,n) cin>>ma[i];
    
    mset(vis,false);
    mset(dX,0);
    mset(dY,0);
    vis[r][c]=true;
    dX[r][c]=dY[r][c]=0;
    ma[r][c]='+';
    left();
    
    ll res = 0;
    forn(i,0,n){
        forn(j,0,m){
            if(vis[i][j]){
                //cout<<i<<" "<<j<<'\n';
                if(dX[i][j]<=x && dY[i][j]<=y){
                    res++;
                    ma[i][j]='+';
                }
            }
        }
    }
    
    //forn(i,0,n) cout<<ma[i]<<'\n';
    
    cout<<res<<'\n';
    
    return 0;
}