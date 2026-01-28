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
        int n,q; cin >> n >> q;
        int a[n], b[n];
        forn(i,n) cin >> a[i];
        forn(j,n) cin >> b[j];

        forn(i,n) a[i] = max(a[i], b[i]);
        dforr(j,1,n) a[j-1] = max(a[j-1], a[j]);

        ll sum[n+1] = {};
        forr(i,1,n+1)
        {
            sum[i] = sum[i-1] + a[i-1];
        }

        forn(k,q)
        {
            int l,r; cin >> l >> r;
            cout << sum[r]-sum[l-1] << " ";
        }

        cout << nl;
    }
    
    return 0;
}