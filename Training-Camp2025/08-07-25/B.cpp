#include <bits/stdc++.h>

#define fst first
#define snd second
#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define forn(i,a,b) for(int i = a; i<b; i++)
#define mset(a,v) memset(a,v,sizeof(a))
#define FIN ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
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

    ll xh = -2;
    ll xv = -1;
    string s; cin>>s;
    for(auto i:s){
        if(i=='0'){
            xv++;
            xv%=4;
            cout<<3<<" "<<xv+1<<'\n';
        }else{
            xh+=2;
            xh%=4;
            cout<<1<<" "<<xh+1<<'\n';
        }
        
    }
    return 0;
}