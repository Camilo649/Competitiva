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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        ll n; cin >> n;
        ll a[n]; forn(i,n) cin >> a[i];

        sort(a, a+n);

        ll count = 0;
        ll i1 = 2;
        forr(i0,0,n-2)
        {
            i1 = max((ll)i0+2, i1);
            while(i1+1 < n && a[i1+1]-a[i0] <= 2) i1++;
            ll k = i1-i0; 
            if (a[i1]-a[i0] <= 2)
                count += (k*(k-1))/2;
        }

        cout << count << nl;
    }
    
    return 0;
}