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

const int MAXN = 1<<17; // ~1e5

using namespace std;
 
ll n, t[2*MAXN];

void buildst(int a[]) {
    forn(i,n) t[n+i] = a[i];
    for (int i = n-1; i > 0; i--)
        t[i] = t[2*i] + t[2*i+1];
}

void updatest(int k, ll x) { // posicion del elemento a actualizar en A, nuevo valor
    k += (ll)n;
    t[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        t[k] = t[2*k] + t[2*k+1];
    }
}

ll sumst(int l, int r) { // indice izquiero del subarbol, indice derecho del subarbol
    l += n; r += n;
    ll s = 0;
    while (l <= r) {
        if (l%2 == 1) s += (ll)t[l++];
        if (r%2 == 0) s += (ll)t[r--];
        l /= 2; r /= 2;
    }
    return s;
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m; cin >> n >> m;
    int a[n]; forn(i,n) cin >> a[i];
    
    buildst(a);
    vector<ll> ans;

    forn(j,m)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int i,v; cin >> i >> v;
            updatest(i, v);
        }
        else
        {
            int l,r; cin >> l >> r;
            ans.pb(sumst(l,r-1));
        }
    }
    
    forn(i,ans.size())
    {
        cout << ans[i] << nl;
    }
    
    return 0;
}