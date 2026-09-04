#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i<(int)b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i>= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second 
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){
    if(DBG) os << "[";
    for(auto& x : v) os << x << (DBG ? ", " : " ");
    return DBG ? os << "]" : os;
}

template<typename S, typename T> ostream& operator<<(ostream& os, const pair<S, T>& p){
    return os << (DBG ? "(" : "") << p.fst << (DBG ? ", " : " ") << p.snd << (DBG ? ")" : "");
}

ll dp[MAXN][451]; //[hasta que posicion considero][hasat que barquito considero]

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,g; cin >> n >> g;
    ll a[n]; forn(i,n) cin >> a[i];
    ll sum[n+1]; sum[0] = 0;
    forn(i,n) sum[i+1] = sum[i] + a[i];

    memset(dp, -INF, sizeof(dp));
    forn(i,n) dp[i][0] = 0;
    forr(b,1,450)
    {
        forr(i,1,n+1)
        {
            // print(i);
            // print(b);
            // print(sum[i] - sum[i-b]);
            dp[i][b] = max(dp[i-1][b], (i-b >= 0 ? dp[i-b][b-1] + g - (sum[i] - sum[i-b]) : -INF));
        }
    }

    ll res = 0;
    forn(b,451) res = max(res, dp[n][b]);

    cout << res << nl;
    
    return 0;
}