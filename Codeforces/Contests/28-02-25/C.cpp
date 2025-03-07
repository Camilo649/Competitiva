#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e5;

using namespace std;
 
int tests;

vector<int> adj[MAXN];
bitset<MAXN> visited;
deque<int> p;
int st,en;
unordered_map<int,vector<pair<int,int>>> subs;
int sst;

void dfs(int r, int u, int d) {
    if(visited[r]) return;
    if(r == st) sst = u;
    visited[r] = 1;
    
    subs[u].pb({d,r});

    for(auto v:adj[r]) {
        dfs(v,u,d+1);
    }
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n;
        cin >> n >> st >> en;
        st--; en--;
        forn(i,n-1)
        {
            int u,v;
            cin >> v >> u;
            v--; u--;
            adj[v].pb(u);
            adj[u].pb(v);
        }

        visited[en] = 1;
        for (auto u : adj[en])
        {
            dfs(u,u,1);
        }

        visited.reset();
        int max_sub = -1;
        for (auto u : adj[en])
        {
            max_sub = max(max_sub, (int)subs[u].size());
            sort(subs[u].begin(),subs[u].end());
        }
        forn(i,max_sub)
        {
            for (auto u : adj[en])
            {
                int j = subs[u].size() - 1;
                while (j>=0 && visited[subs[u][j].second])
                {
                    j--;
                }
                if (j!=-1 && !visited[subs[u][j].second])
                {
                    p.pb(subs[u][j].second);
                    subs[u].pop_back();
                }
            }
        }
        p.pb(en);

        forn(i,p.size())
        {
            cout << p[i]+1 << ' ';
        }
        cout << nl;

        forn(i,n)
        {
            adj[i].clear();
        }
        subs.clear();
        visited.reset();
        p.clear();
    }
    
    return 0;
}