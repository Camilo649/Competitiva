#include <bits/stdc++.h>

#define forr(i,a,b) for(int  i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
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

const int MAXN = 1e5+5;
const int INF  = 1e9;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cout << #x << " = " << x << endl
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

pair<int,int> nxt[MAXN];
bitset<MAXN> visited;
vector<int> adj[MAXN];

void bfs(int r) {
    //print(r);
    visited.reset();
    queue<pair<int,int>> q;
    visited[r] = 1;
    q.push({r,0});
    int d = 0;
    while(!q.empty()) {
        pair<int,int> s = q.front(); q.pop();
        if(s.snd == d) {
            if(nxt[r].snd == d) break;
            d++;
        }
        //print(d);
        for (auto u:adj[s.fst]) {
            //print(u);
            if(visited[u]) continue;
            visited[u] = 1;
            q.push({u,d});

            if(d<nxt[u].snd && r > u) nxt[u] = {r,d};
            else if(d==nxt[u].snd && r > u) nxt[u].fst = min(nxt[u].fst, r); 

            if(u>r) nxt[r] = {min(nxt[r].fst, u),d};
        }
    }
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    fill(nxt, nxt + n, make_pair(INF, INF));
    nxt[n-1] = {n-1,-1}; 
    if(n>1) nxt[n-2] = {n-1,-1};

    forn(i,n-1)
    {
        int u,v; cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dforn(i,n-2)
    {
        if(nxt[i].fst == INF) bfs(i);
    }

    forr(i,0,n)
    {
        cout << nxt[i].fst+1 << " ";
    }
    cout << nl;

    return 0;
}