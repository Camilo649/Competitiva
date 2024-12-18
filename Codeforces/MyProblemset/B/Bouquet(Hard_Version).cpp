#include<bits/stdc++.h>
 
// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
#define CAM
// redefiniciones
typedef unsigned long long ll;
typedef long double ld;
 
using u64 = uint64_t;
 
const int MAXN = -1;
 
using namespace std;
 
int t;
 
int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif
 
    cin >> t;
    while (t--)
    {
        ll n,m;
        cin >> n >> m;
 
        vector<pair<ll,ll>> v(n);
        forn(i,n){
            int f;
            cin >> f;
            v[i].first = f;
        }
        forn(i,n){
            int c;
            cin >> c;
            v[i].second = c;
        }
 
        sort(v.begin(),v.end());
 
        ll mx = 0;
        forn(i,n) {
            ll cuanto1 = min(v[i].second,m/v[i].first);
            ll value = v[i].first*cuanto1;
            mx = max(mx,value);

            if((i==n-1) || (v[i].first != v[i+1].first - 1)) continue;

            ll current = m-value;
            ll cuanto2 = min(v[i+1].second,current/v[i+1].first);
            value += cuanto2*v[i+1].first;
            current = m-value;
            ll added = min({cuanto1,v[i+1].second-cuanto2,current});
            value += added;
            mx = max(mx,value);
        }
        
        cout << mx << nl;
    }
 
    return 0;
}