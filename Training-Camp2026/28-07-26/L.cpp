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

const int MAXN = 2e5 + 7;

using namespace std;
 
int tests;
int n,m,k;
int lk[MAXN], len[MAXN];

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
    // #ifdef GG
    //     freopen("../input.txt", "r", stdin);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tests;

    while (tests--)
    {
        cin >> n >> m >> k;

        for (int i = 0; i < n; i++) lk[i] = i;
        for (int i = 0; i < n; i++) len[i] = 1;

        vector<tuple<int,int,int>> edges;
        forn(i,m)
        {
            int u,v,w;
            cin >> u >> v >> w;
            u--; v--;
            //unite(u,v);
            edges.pb(make_tuple(w,u,v));
        }

        // Kruskal ^-^
        int minmax = 0, maxmax = 0;
        vector<int> added;
        sort(edges.begin(), edges.end());
        for (int i = 0; i < m; i++) {
            if (!same(get<1>(edges[i]), get<2>(edges[i]))) 
            {
                unite(get<1>(edges[i]), get<2>(edges[i]));
                minmax = max(minmax, get<0>(edges[i]));
                added.pb(get<0>(edges[i]));
            }
        }

        auto b = lower_bound(edges.begin(), edges.end(), make_tuple(k, INT_MIN, INT_MIN));
        if(b == edges.end()) b--;
        maxmax = get<0>(*b);
        if(b != edges.end()) b--;
        if(abs(k-get<0>(*b)) < abs(k-maxmax)) maxmax = get<0>(*b);
        if(maxmax < minmax) maxmax = minmax;

        //cout << maxmax << nl;

        if(minmax < k)
        {
            cout << min(abs(k-maxmax), abs(k-minmax)) << nl;
        }
        else
        {
            ll sum = 0;
            for(int w : added)
            {
                if(w > k) sum += w-k;
            }

            cout << sum << nl;
        }
    }
    
    return 0;
}