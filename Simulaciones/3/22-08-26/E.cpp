#include <bits/stdc++.h>

#define forr(i,a,b) for(ll i = (ll) a; i < (ll) b; ++i)
#define forn(i,n) forr(i, 0, n)

#define dforr(i, a, b) for(ll i = (ll) b-1; i >= (ll) a; --i)
#define dforn(i,n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define ALL(x) sort(x.begin(), x.end())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll A,S,L,R; cin >> A >> S >> L >> R;

    ll ans = 0;
    if(A == S) {cout << 1 << nl; return 0;}
    forr(k,1,max(A-L, R-A)+1)
    {
        ll a = 0;
        ll b = (R-A)/k;
        ll s = (b+1)*A + k*((b*(b+1))/2);
        ll maxa = (A-L)/k;
        while (b >= 0 && a <= maxa)
        {
            if(s == S)
            {
                ans++;
                //cout << "a:" << a << " b:" << b << " k:" << k << nl;
                s -= A+k*b;
                b--;
                a++;
                s += A-k*a;
                
            }
            else if(s > S)
            {
                s -= A+k*b;
                b--;
            }
            else
            {
                a++;
                s += A-k*a;
            }
        }
    }

    cout << ans << nl;
    
    return 0;
}