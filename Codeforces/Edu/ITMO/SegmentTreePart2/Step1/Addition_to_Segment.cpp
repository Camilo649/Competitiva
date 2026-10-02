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

ll n, t[2*MAXN] = {}, lazy[2*MAXN] = {};
// void buildst(int a[])
// {

// }

void updateRange(int k, int tl, int tr, int l, int r, ll v) {
    if (lazy[k] != 0) {
        t[k] += (tr - tl + 1) * lazy[k];
        if (tl != tr) {
            lazy[k*2]   += lazy[k];
            lazy[k*2+1] += lazy[k];
        }
        lazy[k] = 0;
    }

    if (tl > r || tr < l)
        return;

    if (tl >= l && tr <= r) {
        t[k] += (tr - tl + 1) * v;
        if (tl != tr) {
            lazy[k*2]   += v;
            lazy[k*2+1] += v;
        }
        return;
    }

    int mid = (tl+tr)/2;
    updateRange(k*2, tl, mid, l, r, v);
    updateRange(k*2+1, mid+1, tr, l, r, v);

    t[k] = t[k*2] + t[k*2+1];
}

ll sumst(int k, int tl, int tr, int l, int r) {
    if (lazy[k] != 0) {
        t[k] += (tr-tl+1) * lazy[k];
        if (tl != tr) {
            lazy[k*2]   += lazy[k];
            lazy[k*2+1] += lazy[k];
        }
        lazy[k] = 0;
    }

    if (tl > r || tr < l)
        return 0;

    if (tl >= l && tr <= r)
        return t[k];

    int mid = (tl+tr)/2;
    return sumst(k*2, tl, mid, l, r) +
           sumst(k*2+1, mid+1, tr, l, r);
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

    forn(i,m)
    {
        int op; cin >> op;
        if(op == 1)
        {
            ll l,r,v; cin >> l >> r >> v;
            updateRange(1,0,n-1,l,r-1,v);
        }
        else
        {
            int i; cin >> i;
            cout << sumst(1,0,n-1,i,i) << nl;
        }
    }

    return 0;
}