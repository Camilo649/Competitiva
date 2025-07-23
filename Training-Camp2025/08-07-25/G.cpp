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

    int n;
    cin >> n;
    vector<ll> v;
    forn(i,n)
    {
        int a;
        cin >> a;
        v.pb(a);
    }

    ll res = v[n-1];
    ll mx = res - 1;
    dforn(i,n-1)
    {
        if (v[i] > mx)
        {
            res += mx;
            mx = max(mx-1, (ll)0);
        }
        else
        {
            res += v[i];
            mx = v[i]-1;
        }
    }
    cout << res << nl;
    
    return 0;
}