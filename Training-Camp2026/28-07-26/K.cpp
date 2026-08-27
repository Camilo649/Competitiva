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
 
int tests;

int lk[MAXN], len[MAXN], mn[MAXN], mx[MAXN];
 
int find(int x) {
    if(x == lk[x]) return x;
    return lk[x] = find(lk[x]);
}
 
bool same(int x, int y) {
    return find(x) == find(y);
}
 
void unite(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (len[a] < len[b]) swap(a,b);
    len[a] += len[b];
    lk[b] = a;
    mn[a] = min(mn[a], mn[b]); 
    mx[a] = max(mx[a], mx[b]); 
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

    for (int i = 0; i < n; i++) lk[i] = i;
    for (int i = 0; i < n; i++) len[i] = 1;
    for (int i = 0; i < n; i++) mn[i] = i;
    for (int i = 0; i < n; i++) mx[i] = i;

    forn(i,m)
    {
        int u,v; cin >> u >> v;
        u--; v--;
        unite(u,v);
    }

    int res = 0;
    int bound = 0;
    forn(i,n-1)
    {
        int a = find(i);
        bound = max(bound, mx[a]);
        if(i<bound)
        {
            if(!same(i,i+1))
            {
                unite(i,i+1);
                res++;
                bound = max(bound, mx[find(i)]);
            }
        }
    }

    cout << res;
    
    return 0;
}