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

int main(){
    ll n = 8;
    vector<pair<ll,string>> v(n); forn(i,0,n) cin>>v[i].snd>>v[i].fst;
    
    pair<ll,string> champ1 = {0,""};
    pair<ll,string> champ2 = {0,""};
    
    forn(i,0,4) champ1=max(champ1,v[i]);
    forn(i,4,8) champ2=max(champ2,v[i]);
    
    if(champ2>champ1) swap(champ1,champ2);
    

    
    cout<<champ1.snd<<" beats "<<champ2.snd<<'\n';
    return 0;
}