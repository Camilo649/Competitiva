#include <bits/stdc++.h>

#define fst first
#define snd second
#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define forn(i,a,b) for(int i = a; i<b; i++)
#define mset(a,v) memset(a,v,sizeof(a))
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MILF
using namespace std;
typedef long long ll;



int main(){
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m; cin>>n>>m;
    
    vector<pair<ll,ll>> c(n); forn(i,0,n) cin>>c[i].fst>>c[i].snd;
    
    vector<pair<ll,ll>> p(m); forn(i,0,m) cin>>p[i].fst, p[i].snd=i; sort(ALL(p));
    
    vector<pair<pair<ll,ll>,ll>> r;
    forn(i,0,n-1){
        ll lo = c[i+1].fst - c[i].snd;
        ll hi = c[i+1].snd - c[i].fst;
        r.pb({{lo, hi}, i});
    }
    
    sort(ALL(r), [](const auto& a, const auto& b) {
        return a.first.second < b.first.second; // ordena por hi creciente
    });
    
    bool yes = true; 
    vector<ll> res(n-1);
    ll ind = 0;
    forn(i,0,SZ(r)){
        
        while(ind<SZ(p) && r[i].fst.fst>p[ind].fst) ind++;
        if(ind>=SZ(p)||p[ind].fst>r[i].fst.snd) yes=false;
        else{
            /*cout<<"Puente "<<i<<" ";
            cout<<r[i].fst.fst<<" "<<r[i].fst.snd<<'\n';
            cout<<p[ind].snd<<'\n';*/
            res[r[i].snd]=(p[ind].snd);
            ind++;
        }
    }
    
    if(!yes) cout<<"No\n";
    else{
        cout<<"Yes\n";
        for(auto i:res) cout<< (i+1) << " "; 
        cout<<'\n';
    }
    
    return 0;
}