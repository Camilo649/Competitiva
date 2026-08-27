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
typedef __int128 ll;
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
    
    int n; cin >> n;
    long double a[n]; forn(i,n) cin >> a[i];

    ll sum[n];
    ll count = 0;
    ll total = 0;
    forn(i,n)
    {
        sum[i] = count*a[i] - total;
        count++;
        total += a[i];
    }
    
    map<ll, ll> cntPorValor;
    forn(j,n)
    {
        ll correccion = 0;
        for (ll v : {a[j]-1, a[j], a[j]+1})
        {
            if (cntPorValor.count(v))
            {
                ll c = cntPorValor[v];
                correccion += (ll)c * a[j] - (ll)v * c;   // mismo tipo de fórmula que antes, pero restringido a este valor v
            }
        }
        sum[j] -= correccion;   // ajustás la contribución de este j
        cntPorValor[a[j]]++;
    }

    ll res = 0;
    forn(i,n)
    {
        res += sum[i];
    }
    
    if (res < 0) { cout << '-'; res = -res; }
    string s;
    if (res == 0) s = "0";
    while (res > 0) { s += char('0' + (int)(res % 10)); res /= 10; }
    reverse(s.begin(), s.end());
    cout << s << nl;
    
    return 0;
}