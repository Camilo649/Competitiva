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
        ll n,h,k; cin >> n >> h >> k;
        ll a[n]; forn(i,n) cin >> a[i];

        ll round = n+k;
        ll sum = 0; forn(i,n) sum += a[i];
        ll ans = (h/sum)*round;
        if(h%sum == 0)
        {
            cout << ans-k << nl;
            continue;
        }
        h = h%sum;

        ll sufix_max[n];
        sufix_max[n-1] = a[n-1];
        dforn(i,n-1) sufix_max[i] = max(a[i], sufix_max[i+1]);
        ll mn = 1e9+8;
        sum = 0;
        forn(i,n)
        {
            sum += a[i];
            mn = min(mn,a[i]);

            if(i == n-1) ans += n;
            else if(sum + max(sufix_max[i+1]-mn, (ll)0) >= h)
            {
                ans += i+1;
                break;
            }
        }

        cout << ans << nl;
    }
    
    return 0;
}