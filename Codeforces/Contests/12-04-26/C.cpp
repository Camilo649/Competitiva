#include <bits/stdc++.h>

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
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        ll n,k,p,q; cin >> n >> k >> p >> q;
        ll a[n]; forn(i,n) cin >> a[i];
        ll b[n]; forn(i,n) b[i] = a[i]%p;
        ll c[n]; forn(i,n) c[i] = (a[i]%q)%p;
        ll sumb[n+1]; sumb[0] = 0; forn(i,n) sumb[i+1] = sumb[i] + b[i];
        ll sumc[n+1]; sumc[0] = 0; forn(i,n) sumc[i+1] = sumc[i] + c[i];
        ll summin[n+1]; summin[0] = 0; forn(i,n) summin[i+1] = summin[i] + min(b[i], c[i]);

        ll ans = 1e18;
        forn(j, (n-k)+1)
        {
            int l = j+1, r = j+k;
            ans = min(ans, summin[l-1] + summin[n] - summin[r] + min(sumb[r]-sumb[l-1], sumc[r]-sumc[l-1]));
        }

        cout << ans << nl;
    }
    
    return 0;
}