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

struct item{
    int sum, l;
};

item single(int v, int i)
{
    return {v,i};
}

item compose(item a, item b)
{
    return {a.sum+b.sum, a.l};
}

int n;
int N;
int t[2*MAXN] = {};
void buildst() {
    //print(N);
    forn(i,N) t[n+i] = 1;
    for (int i = n-1; i > 0; i--)
    {
        t[i] = t[2*i] + t[2*i+1];
    }
}

void updatest(int k) { 
    k += n;
    t[k] = 0;
    for (k /= 2; k >= 1; k /= 2) {
        t[k] = t[2*k] + t[2*k+1];
    }
}

int sumst(int x) {
    int i = 1;
    //print(x);
    while (i < n) {
        //print(i); print(t[2*i]);
        if(t[2*i+1] <= x) {x-=t[2*i+1]; i<<=1;} // Me muevo al hijo izquierdo
        else {i<<=1; i++;}                      // Me muevo al hijo derecho
    }

    return i-n+1;
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
    N = n;
    int size = 1; while(size < n) size<<=1;
    int a[size] = {}; forn(i,N) cin >> a[i]; 
    n = size;

    buildst();

    // forn(i,2*n)
    // {
    //     cout << t[i] << " ";
    // }
    // cout << nl;

    int ans[N];
    dforn(i,N)
    { 
        ans[i] = sumst(a[i]);
        //cout << ans[i] << nl;
        updatest(ans[i]-1);
    }

    forn(i,N) cout << ans[i] << " ";
    cout << nl;
    
    return 0;
}