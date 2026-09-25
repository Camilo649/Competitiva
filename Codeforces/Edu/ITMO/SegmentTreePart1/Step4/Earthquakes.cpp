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
const int INF = 2e9;

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
    int mn;
    int i;
};

item compose(item a, item b)
{
    if(a.mn <= b.mn) return a;
    else return b;
} 

item single(int h, int i)
{
    return {h,i};
}

int n; 
item t[2*MAXN];

void buildst(int a[]) {
    forn(i,n) t[n+i] = single(a[i],i);
    for (int i = n-1; i > 0; i--)
    {
        t[i] = compose(t[2*i],t[2*i+1]);
    }
}

void updatest(int k, int h) { // posicion del elemento a actualizar en A, nuevo valor
    int i = k;
    k += n;
    t[k] = single(h,i);
    for (k /= 2; k >= 1; k /= 2) {
        t[k] = compose(t[2*k],t[2*k+1]);
    }
}

int ans = 0;
// k: nodo actual | tl, tr: rango del nodo | l, r: rango de la consulta | p: poder
void query(int k, int tl, int tr, int l, int r, int p) {


    // 1. Si estamos fuera de la consulta, o np hay edificios, o el más débil es más fuerte que el sismo
    if (l > tr || r < tl || t[k].mn == INF || t[k].mn > p) return;

    // 2. Si este nodo está 100% adentro de la consulta
    if (l <= tl && tr <= r) {
        // Sacamos a los débiles
        while(t[k].mn <= p) {
            ans++;
            updatest(t[k].i, INF);
        }
        return;
    }

    // 3. Paso recursivo: partimos el NODO a la mitad
    int tm = (tl + tr) / 2;
    query(k * 2, tl, tm, l, r, p);
    query(k * 2 + 1, tm + 1, tr, l, r, p);
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
    int size = 1;
    while(size<n) size<<=1;
    int a[size];
    fill(a,a+n,INF);
    n = size;
    
    buildst(a);

    // forn(i,2*n)
    // {
    //     forn(j,40) cout << t[i].h[j] << " ";
    //     cout << "inv: " << t[i].inv;
    //     cout << nl;
    // }

    forn(j,m)
    {
        //print("WASAAAA");
        int op; cin >> op;
        if(op == 1)
        {
            int i,h; cin >> i >> h;
            updatest(i,h);
        }
        else
        {
            int l,r,p; cin >> l >> r >> p;
            ans = 0;
            query(1,0,n-1,l,r-1,p);
            cout << ans << nl;
        }
    }
    
    return 0;
}