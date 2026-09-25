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

const int MAXN = 1<<17;
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

int n, t[2*MAXN];
void buildst(int a[]) {
    forn(i,n) t[n+i] = a[i];
    for (int i = n-1; i > 0; i--)
        t[i] = max(t[2*i], t[2*i+1]);
}

void updatest(int k, int x) { // posicion del elemento a actualizar en A, nuevo valor
    k += n;
    t[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        t[k] = max(t[2*k], t[2*k+1]);
    }
}

int atleastxst(int x) {
    int i = 1;
    while (i < n) {
        //print(i); print(t[2*i]);
        if(t[2*i] >= x) {i<<=1;} // Me muevo al hijo izquierdo
        else {i<<=1; i++;}       // Me muevo al hijo derecho
    }
    return (t[i] >= x ? i-n : -1);
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
    while(size<n) size <<= 1;
    int a[size]; forn(i,n) cin >> a[i];
    forr(i,n,size) a[i] = -INF;
    n = size;

    buildst(a);

    // forn(i,2*n)
    // {
    //     cout << t[i] << " ";
    // }

    forn(j,m)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int i,v; cin >> i >> v;
            updatest(i, v);
            // forn(i,2*n)
            // {
            //     cout << t[i] << " ";
            // }
        }
        else
        {
            int x; cin >> x;
            cout << atleastxst(x) << nl;
        }
    }
    
    return 0;
}