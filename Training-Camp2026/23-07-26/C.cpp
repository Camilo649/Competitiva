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

const int MAXN = 500*500 + 3;
const int INF = INT_MAX;

using namespace std;
 
int tests;

map<pair<int,int>, bool> visited = {};
map<pair<int,int>, vector<pair<int,int>>> adj;
map<int, vector<pair<int,int>>> depth;
int MAXDEPTH = 0;

void dfs(pair<int,int> r, int d) { // <-- pasamos la raiz como parametro
    if(visited[r]) return;
    visited[r] = 1;
    depth[d].pb(r);
    MAXDEPTH = max(MAXDEPTH, d);
    for(auto u: adj[r]) {
        dfs(u, d+1);
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

    int n,m,k; cin >> n >> m >> k;
    string maze[n];
    pair<int,int> r;
    forn(i,n)
    {
        cin >> maze[i];
    }


    //cout << "TODO OK" << nl;

    forn(i,n)
    {
        forn(j,m)
        {
            if(maze[i][j] == '.') 
            {
                r = {i,j};
                break;
            }
        }
    }

    //cout << "TODO OK" << nl;

    forn(i,n)
    {
        forn(j,m)
        {
            if(maze[i][j] != '#')
            {
                if(i>0 && maze[i-1][j] != '#') adj[{i,j}].pb({i-1,j});
                if(i<n-1 && maze[i+1][j] != '#') adj[{i,j}].pb({i+1,j});
                if(j>0 && maze[i][j-1] != '#') adj[{i,j}].pb({i,j-1});
                if(j<m-1 && maze[i][j+1] != '#') adj[{i,j}].pb({i,j+1});
            }
        }
    }

    //cout << "TODO OK" << nl;

    dfs(r,0);

    int ops = 0;
    for (auto it = depth.rbegin(); it != depth.rend(); ++it) {
        if(ops == k) break;
        vector<pair<int,int>> v = it->second;
        forn(i, v.size())
        {
            maze[v[i].fst][v[i].snd] = 'X';
            ops++;
            if(ops == k) break;
        }
    }

    forn(i,n)
    {
        forn(j,m)
        {
            cout << maze[i][j];
        }
        cout << nl;
    }
    cout << nl;
    
    return 0;
}