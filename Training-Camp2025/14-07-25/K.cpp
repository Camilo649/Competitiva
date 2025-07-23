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
    ll r; cin>>r; r*=2;
    ll x, y, xx, yy; cin>>x>>y>>xx>>yy;
    
    ll res = 0;
    ll dx = abs(xx-x);
    ll dy = abs(yy-y);
    res=sqrt(dx*dx+dy*dy)/r;
    ll aux = sqrt(dx*dx+dy*dy);
    if(sqrt(dx*dx+dy*dy)>(double)aux) res++;
    else if(aux%r!=0){
        res++;
    }
    
    
    cout<<res<<'\n';
    
    return 0;
}