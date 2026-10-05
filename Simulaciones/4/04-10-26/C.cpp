#include <bits/stdc++.h>

#define forr(i,a,b) for(ll i = (ll) a; i < (ll) b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second 
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    ll N, P, H; cin>>N>>P>>H;

    string ans = "";
    ll Ni = N;


    ll h = H-1;
    ll hi = h ^ (h>>1);

    forn(i,Ni){
        bool pliegue = hi&(1ll<<i);

        N--;
        ll N2 = (1ll<<N);

        if(P > N2){
            if(pliegue){
                P = 2*N2 -P +1ll;
                ans += 'R';
            }else{
                P = P-N2;
                ans+= 'L';
            }
        }else{
            if(pliegue){
                P = 1ll +(N2-P);
                ans += 'L';
            }else{
                ans+= 'R';
            }
        }
        //cout<<P<<nl;
    }

    cout<<ans<<nl;

    return 0;
}




