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
int p[MAXN];
int st;

void dfs(int r, int &i) { // <-- pasamos la raiz como parametro
    if(visited[r]) return;
    visited[r] = 1;
    
    if (r!=st-1)
    {
        p[i] = r;
        i--;
    }
    

    for(auto u:adj[r]) {
        dfs(u,i);
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
        int n,en;
        cin >> n >> st >> en;
        forn(i,n-1)
        {
            int u,v;
            cin >> v >> u;
            v--; u--;
            adj[v].pb(u);
            adj[u].pb(v);
        }

        if (n==1)
        {
            cout << 1 << nl;
            continue;
        }

        p[0] = st-1;
        
        int index = n-1;
        dfs(en-1,index);

        bool flag = false;
        for(auto v : adj[en-1])
        {
            if (v == p[n-2])
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            forn(i,n)
            {
                cout << p[i]+1 << ' ';
            }
            cout << nl;
        }
        else
        {
            cout << -1 << nl;
        }

        forn(i,n)
        {
            adj[i].clear();
        }
        visited.reset();
        memset(p,0,sizeof(p));
    }
    
    return 0;
}