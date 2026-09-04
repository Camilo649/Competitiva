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
 
const int MAXN = 2500+5;
const ll INF = 1e13;
 
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
 
vector<tuple<int,int,int>> edges;
ll dist[MAXN];
bitset<MAXN> sale;
bitset<MAXN> llega;
bool bf (int v, int n) {
    for(int i = 0; i < n; ++i) {
        dist[i] = -INF;
    }
    dist[0] = 0;
    sale[0] = 1;
    llega[n-1] = 1;
    forn(i,n) {
        for(auto e:edges) {
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = max(dist[b], dist[a]+w);
            if(sale[a]) sale[b] = 1;
            if(llega[b]) llega[a] = 1;
        }
    }
 
    ll dist_aux[n];
    forn(i,n) dist_aux[i] = dist[i];
 
    for(auto e:edges) {
        int a, b, w;
        tie(a, b, w) = e;
        dist[b] = max(dist[b], dist[a]+w);
        if(sale[a]) sale[b] = 1;
        if(llega[b]) llega[a] = 1;
    }
 
    forn(i,n)
    {
        if(!sale[i] || !llega[i]) continue;
        if(dist[i] > dist_aux[i]) return true;
    }
    return false;
}
 
int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m; cin >> n >> m;
    forn(i,m)
    {
        int u,v,w; cin >> u >> v >> w;
        u--; v--;
        edges.pb({u,v,w});
    }
    
    if(bf(0,n)) cout << -1;
    else cout << dist[n-1];
    cout << nl;
    
    return 0;
}