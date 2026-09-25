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
 
int n, t[2*MAXN] = {};

void buildst(int a[]) {
    forn(i,n) t[n+i] = a[i];
    //forn(i,n) {print(n+i); print(t[n+i]);}
    for (int i = n-1; i > 0; i--)
    {
        //print(i); print(t[2*i]); print(t[2*i+1]);
        t[i] = t[2*i] + t[2*i+1];
        //print(t[i]);
    }
}

void updatest(int k) {
    k += n;
    t[k] ^= 1;
    for (k /= 2; k >= 1; k /= 2) {
        t[k] = t[2*k] + t[2*k+1];
    }
}

int kthst(int k) {
    //print(k);
    k++;
    int i = 1;
    while (i < n) {
        //print(i); print(t[2*i]);
        if(t[2*i] < k) {k-=t[2*i]; i<<=1; i++;} // Me muevo al hijo derecho
        else i<<=1;                             // Me muevo al hijo izquierdo
    }
    return i-n;
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
    int a[size] = {}; forn(i,n) cin >> a[i];
    n=size;
    
    //print(n);
    // forn(i,n) cout << a[i] << " ";
    // cout << nl;

    buildst(a);

    // forn(i,16)
    // {
    //     cout << t[i] << " ";
    // }
    // cout << nl;

    forn(j,m)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int i; cin >> i;
            updatest(i);
        }
        else
        {
            int i; cin >> i;
            cout << kthst(i) << nl;
        }
    }
    
    return 0;
}