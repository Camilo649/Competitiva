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

 
ll n; 
pair<ll,ll> t[2*MAXN];

void buildst(pair<int,int> a[]) {
    forn(i,n) 
    {
        if(i%2==0) t[n+i] = a[i];
        else t[n+i] = {a[i].snd,a[i].fst};
    }
    for (int i = n-1; i > 0; i--)
    {
        t[i].fst = t[2*i].fst + t[2*i+1].fst;
        t[i].snd = t[2*i].snd + t[2*i+1].snd;
    }
}

void updatest(int k, ll x) { // posicion del elemento a actualizar en A, nuevo valor
    int i = k;
    k += (ll)n;
    if(i%2==0) {t[k].fst = x; t[k].snd = -x;}
    else       {t[k].fst = -x; t[k].snd = x;}
    for (k /= 2; k >= 1; k /= 2) {
        t[k].fst = t[2*k].fst + t[2*k+1].fst;
        t[k].snd = t[2*k].snd + t[2*k+1].snd;
    }
}

ll sumst(int l, int r) { // indice izquiero del subarbol, indice derecho del subarbol
    bool even = l%2==0;
    l += n; r += n;
    ll s = 0;
    while (l <= r) {
        if (l%2 == 1) s += (even ? (ll)t[l++].fst : (ll)t[l++].snd);
        if (r%2 == 0) s += (even ? (ll)t[r--].fst : (ll)t[r--].snd);
        l /= 2; r /= 2;
    }
    return s;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n; 
    int size = 1;
    while(size<n) size<<=1;
    pair<int,int> a[size];
    forn(i,n) 
    {
        int ai; cin >> ai;
        a[i] = {ai, -ai};
    }
    n = size;
    
    buildst(a);

    //forn(i,2*n) print(t[i]);

    int m; cin >> m;
    forn(j,m)
    {
        int op; cin >> op;
        if(op == 0)
        {
            int i,j; cin >> i >> j;
            updatest(i-1, j);
            // print("ungabunga");
            // forn(i,2*n) print(t[i]);
        }
        else
        {
            int l,r; cin >> l >> r;
            cout << sumst(l-1,r-1) << nl;
        }
    }
    
    return 0;
}