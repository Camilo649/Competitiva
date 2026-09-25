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

const int MAXN = 1<<18; // > 2 * 1e5
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
//     int l, r, size;
// };

// item single(pair<int,int> v)
// {
//     return {v.fst,v.snd, (v.fst == INF ? 0 : 1)};
// }

// item compose(item a, item b)
// {
//     return {min(a.l,b.l), max(a.r,b.r), a.size+b.size};
// }

int n;
int t[2*MAXN] = {};
// void buildst(pair<int,int> a[]) {
//     forn(i,n) t[n+i] = single(a[i]);
//     for (int i = n-1; i > 0; i--)
//     {
//         t[i] = compose(t[2*i], t[2*i+1]);
//     }
// }

void updatest(int k) { 
    k += n;
    t[k] = 1;
    for (k /= 2; k >= 1; k /= 2) {
        t[k] = t[2*k] + t[2*k+1];
    }
}

int sumst(int l, int r) { // indice izquiero del subarbol, indice derecho del subarbol
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
    
    cin >> n;
    int N = n;
    int size = 1;
    while(size<(n<<1)) size <<= 1;
    n = size;

    // buildst(a);

    // forn(i,2*n)
    // {
    //     cout << t[i] << " ";
    // }
    // cout << nl;

    int l[N], ans[N] = {};
    memset(l,-1,sizeof(l));
    forn(i,N<<1)
    {
        int ai; cin >> ai; ai--;
        if(l[ai] == -1)
        {
            l[ai] = i;
        } 
        else 
        {
            ans[ai] = sumst(l[ai], i-1);
            updatest(l[ai]);
        }
    }

    forn(i,N) cout << ans[i] << " ";
    cout << nl;
    
    return 0;
}