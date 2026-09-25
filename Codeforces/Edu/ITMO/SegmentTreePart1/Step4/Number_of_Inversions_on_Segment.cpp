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

const int MAXN = 2<<17; // ~2e5

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

struct item{
    bitset<40> s;
    ll dif = 0;
};

item compose(item a, item b)
{
    item ans;
    forn(i,40) {ans.s[i] = a.s[i]|b.s[i]; ans.dif += a.s[i]|b.s[i];}
    return ans;
} 

item single(int x)
{
    item t;
    t.s[x-1] = 1;
    t.dif = 1;
    return t;
}

int n; 
item t[2*MAXN];

void buildst(item a[]) {
    forn(i,n) t[n+i] = a[i];
    for (int i = n-1; i > 0; i--)
    {
        t[i] = compose(t[2*i],t[2*i+1]);
    }
}

void updatest(int k, int x) { // posicion del elemento a actualizar en A, nuevo valor
    k += n;
    t[k] = single(x);
    for (k /= 2; k >= 1; k /= 2) {
        t[k] = compose(t[2*k],t[2*k+1]);
    }
}

ll sumst(int l, int r) { // indice izquiero del subarbol, indice derecho del subarbol
    l += n; r += n;
    item d;
    while (l <= r) {
        if (l%2 == 1) d = compose(t[l++],d);
        if (r%2 == 0) d = compose(t[r--],d);
        l /= 2; r /= 2;
    }
    return d.dif;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q; cin >> n >> q; 
    int size = 1;
    while(size<n) size<<=1;
    item a[size];
    forn(i,n)
    {
        int ai; cin >> ai;
        a[i] = single(ai);
    }
    n = size;
    
    buildst(a);

    // forn(i,2*n)
    // {
    //     forn(j,40) cout << t[i].h[j] << " ";
    //     cout << "inv: " << t[i].inv;
    //     cout << nl;
    // }

    forn(j,q)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int l,r; cin >> l >> r;
            cout << sumst(l-1,r-1) << nl;
        }
        else
        {
            int i,v; cin >> i >> v;
            updatest(i-1,v);
            // forn(i,2*n)
            // {
            //     forn(j,40) cout << t[i].h[j] << " ";
            //     cout << "inv: " << t[i].inv;
            //     cout << nl;
            // }
        }
    }
    
    return 0;
}