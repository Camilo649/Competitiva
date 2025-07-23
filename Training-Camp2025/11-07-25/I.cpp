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
    ll t; cin>>t;
    while(t--){
        string s; cin>>s;
        if(s!="ROUND") return 0;
        ll m,b; cin>>m>>b;
        if(b<=m/3) cout<<"PLAY\n";
        else cout<<"SKIP\n";
        cout.flush();
        
    }
    return 0;
}