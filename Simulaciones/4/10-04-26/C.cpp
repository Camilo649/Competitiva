#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using u64 = uint64_t;

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

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ull n,k; cin >> n >> k;
    ull c[n]; forn(i,n) cin >> c[i];

    ull p[k-1]; ull base = chrono::steady_clock::now().time_since_epoch().count() | 1;
    p[0] = 1;
    forr(i,1,k-1) p[i] = p[i-1] * base;
    ull h = 0;
    ull S1 = 0;
    forn(i,k-1) S1 += p[i]; 
    map<ull,pair<int,int>> m;
    m[0] = {0,-1};
    int count1 = 0;
    forn(i,n)
    {
        if(c[i] == 1)
        {
            count1++;
            h -= S1;
        }
        else
        {
            h += p[c[i]-2];
        }
        if(m.count(h) == 0) m[h] = {count1, count1};
        else m[h].snd = count1; 
    }

    int ans = 0;
    for(auto [k,v] : m)
    {
        ans = max(ans, v.snd-v.fst);
    }

    cout << ans*k << nl;

    return 0;
}