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

const int MAXN = 1e5+4;
const ll M = 998244353;

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

int lk[MAXN], cnt_v[MAXN], cnt_e[MAXN];
bool selfloop[MAXN];

int find(int x) {
    if(x == lk[x]) return x;
    return lk[x] = find(lk[x]);
}

void unite(int x, int y) {
    int a = find(x);
    int b = find(y);
    lk[b] = a;
    if(a!=b) 
    {
        cnt_v[a] += cnt_v[b];
        cnt_e[a] += cnt_e[b] + 1;
        selfloop[a] |= selfloop[b];
    }
    else {cnt_e[a]++; selfloop[a] = x==y;}
}

int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;
    
    while (tests--)
    {
        ll n; cin >> n;
        int a[n]; forn(i,n) cin >> a[i];
        int b[n]; forn(i,n) cin >> b[i];

        for (int i = 0; i < n; i++) lk[i] = i;
        for (int i = 0; i < n; i++) cnt_v[i] = 1;
        for (int i = 0; i < n; i++) cnt_e[i] = 0;
        for (int i = 0; i < n; i++) selfloop[i] = false;
        ll ans = 1;
        forn(i,n)
        {
            int ai = a[i], bi = b[i];
            ai--; bi--;
            unite(ai,bi);
        }
        
        bitset<MAXN> visited;
        forn(i,n)
        {
            int x = find(i);
            if(!visited[x])
            {
                visited[x] = 1;
                if (cnt_v[x] != cnt_e[x]) ans = 0;
                else if(selfloop[x]) ans = (ans*n)%M;
                else ans = (ans<<1)%M;
            }
        }
        cout << ans << nl;

    }
    
    return 0;
}