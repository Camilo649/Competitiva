#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)

#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define pb push_back
#define fsr first
#define snd suseconds_t
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e6 + 4;

using namespace std;

ll h[MAXN] = {};
void getDiv(int n) {
    for (int d = 1; d * d <= n; d++) {
        if (n%d == 0) {
            h[d]++;
            h[n/d]++;
        }
        if (d*d == n) h[n/d]--;
    }
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int a[n]; forn(i,n) cin >> a[i];
    int m; cin >> m;
    int b[m]; forn(j,m) cin >> b[j];

    forn(i,n) getDiv(a[i]);

    ll res = 0;
    forn(j,m) res += h[b[j]];

    cout << res << nl;
    
    return 0;
}