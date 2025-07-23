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

const int MAXN = 500+5;

int main(){ FIN;
    
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<vector<ll>> m(n,vector<ll>(n)); forn(i,0,n) forn(j,0,n) cin>>m[i][j];
        
        ll cen=m[n/2][n/2];
        ll minUL;
        ll minUR;
        ll minDL;
        ll minDR;
        ll minUU;
        ll minDD;
        ll minLL;
        ll minRR;
        
        
        minUU=minDD=minRR=minLL=minDR=minDL=minUR=minUL=100000000000+5;
        
        
        //Down
        forn(i,n/2,n){
            forn(j,0,(n/2)+1){
                minDL=min(minDL,m[i][j]);
            }
        }
        
        forn(i,n/2,n){
            forn(j,n/2,n){
                minDR=min(minDR,m[i][j]);
            }
        }
        
        //Up
        forn(i,0,n/2+1){
            forn(j,0,(n/2)+1){
                minUL=min(minUL,m[i][j]);
            }
        }
        
        forn(i,0,n/2+1){
            forn(j,n/2,n){
                minUR=min(minUR,m[i][j]);
            }
        }
        
        //UU
       forn(i,0,(n/2)+1) minUU=min(minUU,m[i][n/2]);
       
        //DD
       forn(i,(n/2),n) minDD=min(minDD,m[i][n/2]);
        
        //LL
       forn(j,0,(n/2)+1) minLL=min(minLL,m[n/2][j]);
       
        //RR
       forn(j,(n/2),n) minRR=min(minRR,m[n/2][j]);
       
       ll res = cen;
       res=min(res, minUL+minUR+minDL+minDR);
       res=min(res, minUL+minUR+minDD);
       
       res=min(res, minUU+minDD);
       res=min(res, minUU+minDL+minDR);
       
       res=min(res, minLL+minRR);
       res=min(res, minLL+minUR+minDR);
       
       res=min(res, minRR+minUL+minDL);
       
       cout<<res<<'\n';
        
    }
    return 0;
}