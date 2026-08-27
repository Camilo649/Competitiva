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

const int MAXN = 1001;

using namespace std;

int lk[MAXN], len[MAXN], ciclos[MAXN] = {};

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

    for (int i = 0; i < n; i++) lk[i] = i;
    for (int i = 0; i < n; i++) len[i] = 1;
    vector<pair<int,int>> destroy;
    vector<pair<int,int>> build;
    forn(i,n-1)
    {
        int u,v; cin >> u >> v; u--; v--;
        if(same(u,v)) 
        {
            ciclos[find(u)]++;
            destroy.pb({u,v});
        }
        unite(u,v);
    }

    set<int> s;
    vector<int> roots;
    forn(i,n) 
    {
        if(s.count(find(i)) == 0) roots.pb(find(i));
        s.insert(find(i));
    }

    forn(r,roots.size()-1)
    {
        build.pb({roots[r], roots[r+1]});
    }

    cout << destroy.size() << nl;
    forn(i,destroy.size())
    {
        cout << destroy[i].fst+1 << " " << destroy[i].snd+1 << " ";
        cout << build[i].fst+1 << " " << build[i].snd+1 << nl;
    }
    
    return 0;
}