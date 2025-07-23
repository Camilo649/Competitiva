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

const int MAXN = 30;

vector<ll> adj[MAXN];
vector<ll> radj[MAXN];

vector<char> topo;
bool vis[MAXN];
bool visa[MAXN];
bool yes = true;

void dfs(ll nd, ll p){
    if(visa[nd]){ yes=false; } //cout<<"e  "<<char(nd+'a')<<" "<<char(p+'a')<<'\n'; }
    if(vis[nd]) return;
    //cout<<char(nd+'a')<<" "<<char(p+'a')<<"--------"<<'\n';
    vis[nd]=true;
    visa[nd]=true;
    for(auto i:adj[nd]) {
        //cout<<(char)(i+'a')<<" ";
        
    } //cout<<'\n';
        for(auto i:adj[nd]) {
    dfs(i,nd);
    
        }
    topo.pb(nd+'a');
    visa[nd]=false;
}

int main(){
    ll n; cin>>n;
    vector<string> str(n);
    forn(i,0,n) cin>>str[i];
    
    //cout<<"ingreso listo\n";
    
    forn(i,0,n){
        forn(h,i+1,n){
            bool check = false;
            forn(j,0,(ll)min(SZ(str[i]), SZ(str[h]))){
                if(str[i][j]!=str[h][j]){
                    adj[str[h][j]-'a'].pb( str[i][j]-'a');
                    radj[str[i][j]-'a'].pb( str[h][j]-'a');
                    check = true;
                    break;
                }
            }
            if(!check){
                if(SZ(str[i])>SZ(str[h])){ yes=false;  }
            }
        }
        
        
    }
    
    forn(i,0,26){
        //cout<<(char)(i+'a')<<"------"<<'\n';
        //for(auto i:adj[i]) cout<<(char)(i+'a')<<" "; cout<<'\n';
    }
    //cout<<"dfs time\n";
    //forn(i,0,26) cout<<SZ(radj[i])<<" "<<SZ(adj[i])<<" "<<(char)(i+'a')<<'\n';
    forn(i,0,26) if(!vis[i]) dfs(i,-1);
    
    if(!yes){ cout<<"Impossible\n";
    return 0;
    }
    
    
    forn(i,0,26)if(!vis[i] && SZ(adj[i])==0){
        //topo.pb('a'+i);
    }
    //cout<<"llega\n";
    
    for(auto i:topo) cout<<i; cout<<'\n';
    
    return 0;
}