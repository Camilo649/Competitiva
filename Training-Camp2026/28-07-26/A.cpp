

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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 200000 + 6;

using namespace std;
 
int n;
vector<int> adj[MAXN];


bitset<MAXN> visited;
bool flag = true;
int colors[MAXN];

void dfs(int r,int c) { // <-- pasamos la raiz como parametro
    if(visited[r]) return;
    visited[r] = 1;
    if(colors[r] != c)
    {
        flag = false;
        return;
    }
    // process node r
    for(auto u:adj[r]) {
        dfs(u,c);
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
    
    cin >> n;

    forn(i,n-1){
        int u = 0;
        int v = 0; 
        cin>>v>>u;
        u -= 1;
        v -= 1;
        adj[u].push_back(v);
        adj[v].pb(u);
    }

    forn(j,n){
        int c;
        cin>>c; 
        colors[j] = c;
    } 

    int r1 = -1, r2 = -1;
    forn(u, n)
    {
        for(auto y : adj[u]) 
        {
            if(colors[u] != colors[y])
            {
                r1 = u;
                r2 = y;
            }
        }
    } 


    if(r1 == -1)
    {
        cout << "YES" << nl;
        cout << 1 << nl;
        return 0;
    }

    visited[r1] = 1;
    for(auto u : adj[r1])
    {
        flag = true;
        dfs(u, colors[u]);
        if (!flag) break;
    }

    if(flag)
    {
        cout << "YES" << nl;
        cout << r1+1 << nl;
    }
    else
    {
        visited.reset();
        visited[r2] = 1;
        for(auto u : adj[r2])
        {
            flag = true;
            dfs(u, colors[u]);
            if (!flag) break;
        }
        
        if(flag)
        {
            cout << "YES" << nl;
            cout << r2+1 << nl;
        }
        else
        {
            cout << "NO" << nl;
        }
    }
    

    return 0;
}