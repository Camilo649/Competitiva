#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
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

const int MAXN = 1e5 + 5;

using namespace std;

int lk[MAXN], mn[MAXN], parent[MAXN];

int find(int u) {
    if (parent[u] == u) return u;
    
    int p = parent[u];
    parent[u] = find(p); // Compresión de camino clásica
    
    // Al subir de la recursión, actualizo mi mínimo con el de mi ancestro
    mn[u] = min(mn[u], mn[p]);
    
    return parent[u];
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

void unite(int x, int y)
{
    parent[y] = x;
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
    int p[n]; forn(i,n) cin >> p[i];
    forn(i,n) lk[i] = i;
    forn(i,n) mn[i] = p[i];
    forn(i,n) parent[i] = i;


    forn(k,m)
    {
        char c; cin >> c;
        if(c == '?')
        {
            int k; cin >> k; k--;
            find(k);
            cout << mn[k] << nl;
        }
        else
        {
            int i,j; cin >> i >> j; i--; j--;
            unite(i,j);
        }
    }

    return 0;
}