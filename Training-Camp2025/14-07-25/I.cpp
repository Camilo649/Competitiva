#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fst first
#define snd second
#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define forn(i,a,b) for(int i = a; i<b; i++)
#define mset(a,v) memset(a,v,sizeof(a))
//#define FIN ios::sync_

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update> ims;

const int MAXN = 200000+5;

int main(){
    ll n; cin>>n;
    vector<ll> a(n); forn(i,0,n) cin>>a[i];
    
    vector<pair<ll,ll>> pp(n); 
    forn(i,0,n) pp[i]={i+1,a[i]};
    
    sort(ALL(pp));
    
    ims cant;
    set<pair<ll,ll>> ms; forn(i,0,n) ms.insert({a[i],i+1});
    forn(i,0,n) cant.insert(pair<ll,ll>({i+1,a[i]}));
    
    ll res = 0;
    
    ll ind = 0;
    forn(i,1,n+1){
        while(!ms.empty() && (*ms.begin()).fst<i){
            cant.erase(cant.find({(*ms.begin()).snd,(*ms.begin()).fst}));
            ms.erase(ms.begin());
        }
        if(cant.find(pair<ll,ll>({i,a[i-1]}))!=cant.end()){
            cant.erase(cant.find(pair<ll,ll>({i,a[i-1]})));
        }
        
        //for(auto j:cant) cout<<"("<<j.fst<<","<<j.snd<<") "; cout<<'\n';
        
        auto it = cant.upper_bound(pair<ll,ll>({a[i-1],100000000000}));
        if(it==cant.end()) res+=SZ(cant);
        else{
            res+=cant.order_of_key(*it);
        }
        
    }
    
    cout<<res<<'\n';
    return 0;
}