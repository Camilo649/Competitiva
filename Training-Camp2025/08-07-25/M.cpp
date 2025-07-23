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
 
long double pr = 1e-7;

int main(){
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n,R; cin>>n>>R;
    
    long double ang = (long double)360/(long double)n;
    
    long double l,r; l = 0; r = 1000000;
    while(l<=r){
        long double mid = (l+r)/2;
        
        long double dis = sqrtl((R+mid)*(R+mid)*2-2*(R+mid)*(R+mid)*cos(ang*3.14159265359/(long double)180));
        
        //cout<<l<<" "<<r<<" "<<mid<<" "<<dis<<'\n';
        //cout<<cos((long double)60*(long double)3.1415926/(long double)180)<<'\n';
        //ll aux; cin>>aux;
        
        if(dis>2*mid) l=mid;
        if(dis<2*mid) r=mid;
   
        if(abs(dis-(2*mid))<pr){
            //cout<<pr<<'\n';
            cout<<setprecision(16);
            cout<<mid<<'\n';
            return 0;
        }
    }
    return 0;
}