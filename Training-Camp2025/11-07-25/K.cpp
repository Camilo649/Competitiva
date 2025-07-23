#include <bits/stdc++.h>

#define fst first
#define snd second
#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset(a,v,size_of(a))
#define forn(i,a,b) for(int i = a; i< b; i++)
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

using namespace std;
typedef long long ll;

int main(){ 
    ll n; cin>>n;
    vector<string> name(n); 
    vector<vector<ll>> t(n,vector<ll>(3));
    
    //cout<<"ingreso\n";
    forn(i,0,n) cin>>name[i]>>t[i][0]>>t[i][1]>>t[i][2];
    
    //cout<<"se ingreso todo\n";
    
    vector<ll> tim;
    
    forn(i,0,n){
        ll mini = 1000000000000000;
        forn(j,0,3) if(t[i][j]!=-1){
            mini=min(mini,t[i][j]);
        }
        tim.pb(mini);
    }
    
    sort(ALL(tim));
    
    ll res = 0;
    ll cnt = 0;
    for(auto i:tim){
        cnt+=i;
        if(cnt<=300) res++;
    }
    
    cout<<res<<'\n';
    return 0;
}