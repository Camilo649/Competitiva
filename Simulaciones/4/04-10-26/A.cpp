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

    const int MAXN = 1e4 + 5;

    using namespace std;

    bitset<MAXN> visited1, visited2, visited3;
    vector<int> adj[MAXN];

    void dfs1(int r, int f) {
        if(visited1[r] || r==f) return;
        visited1[r] = 1;
        for(auto u : adj[r])
        {
            dfs1(u,f);
        }
    }

    void dfs2(int r, int f) {
        if(visited2[r] || r==f) return;
        visited2[r] = 1;
        for(auto u : adj[r])
        {
            dfs2(u,f);
        }
    }

    bool dfs3(int r, int f) {
        if(visited3[r] || r==f) return false;
        visited3[r] = 1;
        if(visited1[r] && visited2[r]) return true;
        for(auto u : adj[r])
        {
            if(dfs3(u,f)) return true;
        }
        return false;
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
        vector<pair<int,int>> hijos;

        forn(i,n)
        {
            int u,v; cin >> u >> v; u--; v--;
            adj[u].pb(i); adj[v].pb(i);
            hijos.pb({u,v});
        }

        forn(i,n)
        {
            visited1.reset(); visited2.reset(); visited3.reset();
            int h1 = hijos[i].fst, h2 = hijos[i].snd;
            dfs1(h1,i); dfs2(h2,i);
            bool flag = false;
            for(auto p : adj[i]) {
                if(dfs3(p,i)) {flag = true; break;}
            }
            if(flag) cout << "Y";
            else cout << "N";
        }
        cout << nl;

        return 0;
    }