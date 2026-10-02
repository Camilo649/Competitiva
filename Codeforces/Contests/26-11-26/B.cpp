#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

// Debugging
#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    if (DBG) os << "[";
    for (auto& x : v) os << x << (DBG ? ", " : " ");
    return DBG ? os << "]" : os;
}

template<typename S, typename T> ostream& operator<<(ostream& os, const pair<S, T>& p) {
    return os << (DBG ? "(" : "") << p.fst << (DBG ? ", " : " ") << p.snd << (DBG ? ")" : "");
}

ll calculate (ll x)
{
    ll res = 0;
    ll y = 1;
    forn(j,9) y*=10;
    forn(i,10)
    {
        ll num = x/y;
        res += num*num;
        x %= y;
        y/=10;
    }

    return res;
}

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
        int n; cin >> n;
        ll a[n]; forn(i,n) cin >> a[i];

        map<ll,ll> m;
        forn(i,n)
        {
            forn(j,1000)
            {
                a[i] = calculate(a[i]);
            }
            m[a[i]]++;
        }

        // forn(i,n) cout << a[i] << " ";
        // cout << nl;

        ll ans = 0;
        for(auto [a,c] : m)
        {
            ans += c*(c-1);
        }

        cout << ans/2 << nl;
    }
    
    return 0;
}