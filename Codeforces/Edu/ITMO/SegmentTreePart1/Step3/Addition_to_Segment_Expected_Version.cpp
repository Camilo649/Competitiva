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

const int MAXN = 1<<17; // > 1e5
const int INF  = 1e9;

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

// struct item{
//     ll l, r, v;
// };

// item single(ll i)
// {
//     return {i,i,0};
// }

// item compose(item a, item b)
// {
//     return {min(a.l,b.l), max(a.r,b.r), a.v+b.v};
// }

int n;
ll t[2*MAXN] = {};
// void buildst() {
//     forn(i,n) t[n+i] = single(i);
//     for (int i = n-1; i > 0; i--)
//     {
//         t[i] = compose(t[2*i], t[2*i+1]);
//     }
// }

void updatest(int k, ll x) { // posicion del elemento a actualizar en A, nuevo valor
    k += (ll)n;
    t[k] += x;
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
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m; cin >> n >> m;
    //int N = n;
    int size = 1;
    while(size<n) size <<= 1; 
    n = size;

    //buildst();

    // forn(i,2*n)
    // {
    //     cout << t[i] << " ";
    // }
    // cout << nl;

    forn(j,m)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int l,r,v; cin >> l >> r >> v;
            updatest(l,v);
            if(r!=n)updatest(r,-v);
        }
        else
        {
            int i; cin >> i;
            cout << sumst(0,i) << nl;
        }
    }
    
    return 0;
}