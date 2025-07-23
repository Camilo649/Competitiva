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

struct lett{
    ll left;
    ll right;
    char val = '0';
};

int main(){
    string s; cin>>s;
    
    set<pair<ll,char>> st; forn(i,0,SZ(s)) st.insert({i,s[i]});
    
    auto l = st.begin();
    auto r = l; r++;
    
    while(r!=st.end()){
        //cout<<(*l).snd<<" "<<(*r).snd<<'\n';
        if((*l).snd==(*r).snd){
            auto nl = l; nl--;
            auto nr = r; nr++;
            
            if(l==st.begin()) nl=nr, nr++;
            st.erase(l);
            st.erase(r);
            if(nr==st.end()) break;
            l=nl;
            r=nr;
        }else{
            l=r, r++;
        }
    }
    for(auto i:st) cout<<i.snd; cout<<'\n';
    //forn(i,0,SZ(s)) if(s[i]!='0') cout<<s[i]; cout<<'\n';
    return 0;
}