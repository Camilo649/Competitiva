#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
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

const int MAXN = 1e5 + 4;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << endl
#endif

vector<int> adj[MAXN];
bitset<MAXN> visited;
bitset<MAXN> used;
vector<int> levels[MAXN];
int parent[MAXN];
int D = 0;

void dfs(int r, int p, int d)
{
    //print(r); print(p); print(d);
    D = max(D,d);
    if(visited[r]) return;
    visited[r] = 1;
    parent[r] = p;
    levels[d].pb(r);

    for(auto u:adj[r])
    {
        dfs(u,r,d+1);
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

    int n,k; cin >> n >> k;
    forr(i,1,n)
    {
        int j; cin >> j; j--;
        //cout << i << " " << j << nl;
        adj[i].pb(j);
        adj[j].pb(i);
    }

    dfs(0,-1,0);

    vector<int> v;
    dforn(d,D+1)
    {
        //print(d);
        for(auto u:levels[d])
        {
            //print(d); print(u);
            int c = 0;
            while (u != -1 && !used[u])
            {
                //print(u);
                c++;
                used[u] = 1;
                u = parent[u];
            }
            v.pb(c);
        }
    }

    sort(v.rbegin(), v.rend());

    int ans = 0;
    forn(i, min(k,SZ(v)))
    {
        ans += v[i];
    }

    cout << ans << nl;

    return 0;
}