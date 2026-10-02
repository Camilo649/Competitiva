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

int n, t[2*MAXN] = {}, lazy[2*MAXN] = {};
// void buildst(int a[])
// {

// }

void updateRange(int k, int tl, int tr, int l, int r, int v) {
    if (lazy[k] != 0) {
        t[k] = max(t[k], lazy[k]);
        if (tl != tr) {
            lazy[2*k]   = max(lazy[2*k], lazy[k]);
            lazy[2*k+1] = max(lazy[2*k+1], lazy[k]);
        }
        lazy[k] = 0;
    }

    if (tl > r || tr < l)
        return;

    if (tl >= l && tr <= r) {
        //print(k); print(tl); print(tr); print(l); print(r); print(v);
        t[k] = max(t[k], v);
        if (tl != tr) {
            lazy[2*k]   = max(lazy[2*k], v);
            lazy[2*k+1] = max(lazy[2*k+1], v);
        }
        return;
    }

    int mid = (tl+tr)/2;
    updateRange(2*k, tl, mid, l, r, v);
    updateRange(2*k+1, mid+1, tr, l, r, v);

    t[k] = max(t[2*k], t[2*k+1]);
}

int assignst(int k, int tl, int tr, int l, int r) {
    if (lazy[k] != 0) {
        t[k] = max(t[k], lazy[k]);
        if (tl != tr) {
            lazy[2*k]   = max(lazy[2*k], lazy[k]);
            lazy[2*k+1] = max(lazy[2*k+1], lazy[k]);
        }
        lazy[k] = 0;
    }

    if (tl > r || tr < l)
        return 0;

    if (tl >= l && tr <= r)
        return t[k];

    int mid = (tl+tr)/2;
    return max(assignst(2*k, tl, mid, l, r),
               assignst(2*k+1, mid+1, tr, l, r));
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
    int size = 1; while(size<n) size<<=1;
    n = size;

    forn(i,m)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int l,r,v; cin >> l >> r >> v;
            updateRange(1,0,n-1,l,r-1,v);
        }
        else
        {
            int i; cin >> i;
            cout << assignst(1,0,n-1,i,i) << nl;
        }
    }

    return 0;
}