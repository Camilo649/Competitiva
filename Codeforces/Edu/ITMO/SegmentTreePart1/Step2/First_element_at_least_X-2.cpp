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

int n;
pair<int,int> t[2*MAXN]; // {max, r}
void buildst(int a[]) {
    forn(i,n) t[n+i] = {a[i], i};
    for (int i = n-1; i > 0; i--)
    {
        t[i].fst = max(t[2*i].fst, t[2*i+1].fst);
        t[i].snd = t[2*i+1].snd;
    }
}

void updatest(int k, int x) { // posicion del elemento a actualizar en A, nuevo valor
    k += n;
    t[k] = {x, k-n};
    for (k /= 2; k >= 1; k /= 2) {
        t[k].fst = max(t[2*k].fst, t[2*k+1].fst);
    }
}

int atleastxst(int x, int k, int l) {
    if(t[k].snd < l || t[k].fst < x) return -1;
    if(k>=n && t[k].fst < x) return -1;
    if(k>=n && t[k].fst >= x) return k-n;
    int cl = atleastxst(x,2*k,l);
    if(cl == -1) return atleastxst(x,2*k+1,l);
    else return cl;
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
            int x,l; cin >> x >> l;
            int ans = atleastxst(x,1,l);
            cout << ans << nl;
        }
    }
    
    return 0;
}