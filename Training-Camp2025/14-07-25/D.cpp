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

ll dp[MAXN][5];
ll a[MAXN];

vector<ll> cnt[MAXN];
ll n;

ll f(ll x, ll y){
    ll &res = dp[x][y];
    if(res!=-1) return res;
    if(x==n) return 0;
    if(y==0){
        res=0;
        res=f(x+1,0);
        ll ind = lower_bound(ALL(cnt[a[x]]),x)-cnt[a[x]].begin();
        ind++;
        if(ind<SZ(cnt[a[x]])){
            res=max(res,f(cnt[a[x]][ind],1) + (cnt[a[x]][ind] - x));
            res=max(res,f(cnt[a[x]][ind]+1,0) + (cnt[a[x]][ind] - x)+1 );
        }
    }else{
        res=0;
        ll ind = lower_bound(ALL(cnt[a[x]]),x)-cnt[a[x]].begin();
        ind++;
        if(ind<SZ(cnt[a[x]])){
            res=max(res,f(cnt[a[x]][ind],1) + (cnt[a[x]][ind] - x));
            res=max(res,f(cnt[a[x]][ind]+1,0) + (cnt[a[x]][ind] - x)+1 );
        }else{
            res=-100000000000000;
        }
    }
    return res;
}

int main(){
    ll t; cin>>t;
    while(t--){
    cin>>n;
    forn(i,0,n+5)forn(j,0,5) dp[i][j]=-1;
    forn(i,0,n+5) cnt[i].clear();
    forn(i,0,n) cin>>a[i], cnt[a[i]].pb(i);
    
    
    cout<<f(0,0)<<'\n';
    }
    return 0;
}