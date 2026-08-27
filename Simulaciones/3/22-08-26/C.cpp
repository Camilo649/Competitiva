#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i, 0, n)

#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
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

int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    ll a[n]; forn(i,n) cin >> a[i];
    ll b[n]; forn(j,n) cin >> b[j];

    sort(a,a+n); sort(b,b+n);

    ll res[n];
    forn(k,n)
    {
        res[k] = a[k] + b[n-k-1];
    }
    sort(res, res+n);

    cout << res[n-1] - res[0] << nl;

    return 0;
}