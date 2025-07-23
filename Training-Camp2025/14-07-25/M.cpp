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

int main(){
    ll n,q; cin>>n;
    vector<ll> a(n); forn(i,0,n) cin>>a[i];
    
    cin>>q;
    vector<pair<ll,ll>> qu(q); forn(i,0,q) cin>>qu[i].fst, qu[i].snd=i;
    
    sort(ALL(qu));
    sort(ALL(a));
    
    ll rres = 0;
    ll ind = 0;
    vector<ll> res(q);
    
    forn(i,0,q){
        while(ind<n && a[ind]<=qu[i].fst) ind++;
        res[qu[i].snd]=ind;
    }
    
    for(auto i:res) cout<<i<<'\n';
    return 0;
}