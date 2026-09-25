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

const int MAXN = 1<<17; // ~1e5

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

struct item {
    ll seg  = 0;
    ll pref = 0;
    ll suf  = 0;
    ll sum  = 0;
};

item single(int x)
{
    return {(ll)max(x,0),(ll)max(x,0),(ll)max(x,0),(ll)x};
}

item compose(item a, item b)
{
    item res;
    res.seg  = max(max(max(a.seg, b.seg),a.suf+b.pref),0LL);
    res.pref = max(max(a.pref,a.sum+b.pref),0LL);
    res.suf  = max(max(b.suf,b.sum+a.suf),0LL);
    res.sum  = a.sum + b.sum;
    return res; 
}

int n;
item t[2*MAXN];

void buildst(int a[]) {
    forn(i,n) t[n+i] = single(a[i]);
    for (int i = n-1; i > 0; i--)
        t[i] = compose(t[2*i], t[2*i+1]);
}

void updatest(int k, int x) { // posicion del elemento a actualizar en A, nuevo valor
    k += n;
    t[k] = single(x);
    for (k /= 2; k >= 1; k /= 2) {
        t[k] = compose(t[2*k], t[2*k+1]);
    }
}

// ll sumst(int l, int r) { // indice izquiero del subarbol, indice derecho del subarbol
//     l += n; r += n;
//     ll mx = 0;
//     while (l <= r) {
//         if (l%2 == 1) mx = max(mx,t[l++].seg);
//         if (r%2 == 0) mx = max(mx,t[r--].seg);
//         l /= 2; r /= 2;
//     }
//     return mx;
// }

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m; cin >> n >> m;
    int size = 1;
    while(size<n) size<<=1;
    int a[size] = {}; forn(i,n) cin >> a[i];
    n=size;
    
    buildst(a);

    cout << t[1].seg << nl;
    while(m--)
    {
        int i,v; cin >> i >> v;
        updatest(i,v);
        cout << t[1].seg << nl;
    }
    
    return 0;
}