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

const int MAXN = 1e6, M = 998244353;
ll F[MAXN];

using namespace std;
 
int tests;

ll powmod(ll a, ll b) {
    ll res = 1;
    a %= M;

    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }

    return res;
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    F[0] = 1;
    for(ll i = 1; i < MAXN; i++) F[i] = F[i-1]*i %M;

    while (tests--)
    {
        ll n,m,r,c; cin >> n >> m >> r >> c;
        ll res = powmod(2, r*c-1);
        res = res * powmod(powmod(2, c - 1), n - r) % M;
        res = res * powmod(powmod(2, r - 1), m - c) % M;

        cout << res << nl;
    }
    
    return 0;
}