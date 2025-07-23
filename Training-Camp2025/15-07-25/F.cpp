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


int main(){ FIN;
    ll t; cin>>t;
    while(t--){
        vector<ll> let(30,0);
        
        string s; cin>>s;
        forn(i,0,SZ(s)) let[s[i]-'a']++;
        
        ll cnt = 0;
        forn(i,0,30) if(let[i]>0) cnt++;
        
        if(SZ(s)==1){
            cout<<"YES\n";
            cout<<s<<'\n';
            continue;
        }
        
        if(cnt<3){ 
            if(cnt==2){
                bool yes =false;
                forn(i,0,30){
                    if(let[i]==1 && !yes) cout<<"YES\n"<<char(i+'a'), let[i]--, yes = true;
                }
                if(!yes){
                    cout<<"NO\n";
                    continue;
                }
                forn(i,0,30){
                    forn(j,0,let[i]) cout<<char(i+'a');
                }
                cout<<'\n';
                continue;
            }else{
               cout<<"NO\n"; continue; 
            }
        }
        
        cout<<"YES\n";
        forn(i,0,30){
            if(let[i]>0&&cnt>0) let[i]--, cout<<char(i+'a'), cnt--;
        }
        
        forn(i,0,30){
            forn(j,0,let[i]) cout<<char(i+'a');
        }
        cout<<'\n';
        
        
    }
    
    
    
    
    return 0;
}