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

const int MAXN = 200+5;
const int MAXP = 10;

ll n;
ll dp[MAXN][MAXP][MAXP];

vector<string> str;

vector<vector<ll>> op[MAXP];

ll f(ll x, ll y, ll z){
    ll &res = dp[x][y][z];
    if(res!=-1) return res;
    if(x>=n-1) return 0;
    
    ll rnewz = 0; 
    if(x+2<n) forn(i,0,2) if(str[i][x+2]=='X') rnewz|=(1<<i);
    
    res=f(x+1,z,rnewz);
    
    forn(i,1,5){
        bool yes = true;
        ll newy=y;
        ll newz=z;
        
        forn(yy,0,SZ(op[i][0])){
            if(y & (1<<yy) && op[i][0][yy]){
                yes=false;
            }   
            if(op[i][0][yy]) newy|=(1<<yy);
        }
        
        forn(zz,0,SZ(op[i][1])){
            if(z & (1<<zz) && op[i][1][zz]){
                yes=false;
            }   
            if(op[i][1][zz]) newz|=(1<<zz);
        }
        
        
        
        if(yes){
            res=max(res,f(x+1,newz,rnewz)+1);
            /*cout<<x<<" op "<<i<<" "<<yes<<'\n';
            cout<<"y:\n";
            forn(i,0,2) cout<<(y&(1<<i))<<'\n';
            cout<<"z:\n";
            forn(i,0,2) cout<<(z&(1<<i))<<'\n';
            
            cout<<"newz:\n";
            forn(i,0,2) cout<<(newz&(1<<i))<<'\n';*/
            
        }else{
            /*cout<<x<<" no op "<<i<<" "<<yes<<'\n';
            cout<<"y:\n";
            forn(i,0,2) cout<<(y&(1<<i))<<'\n';
            cout<<"z:\n";
            forn(i,0,2) cout<<(z&(1<<i))<<'\n';
            
            cout<<"newz:\n";
            forn(i,0,2) cout<<(newz&(1<<i))<<'\n';*/
        }
    }
    return res;
}

int main(){
    op[0]= {{0,0},
            {0,0}};
            
    op[1]= {{1,0},
            {1,1}};
    
    op[4]= {{0,1},
            {1,1}};
            
    op[3]= {{1,1},
            {1,0}};
            
    op[2]= {{1,1},
            {0,1}};
    
    
    mset(dp,-1);
    
    str.resize(2);
    forn(i,0,2) cin>>str[i];
    
    n=SZ(str[0]);
    //cout<<"Llega\n";
    
    ll rnewy = 0;
    ll rnewz = 0;
    if(SZ(str[0])>0) forn(i,0,2) if(str[i][0]=='X') rnewy|=(1<<i);
    if(SZ(str[0])>1) forn(i,0,2) if(str[i][1]=='X') rnewz|=(1<<i);
    
    cout<<f(0,rnewy,rnewz)<<'\n';
    
    return 0;
}