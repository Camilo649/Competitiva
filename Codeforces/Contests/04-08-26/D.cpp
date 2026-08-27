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
    // redefiniciones
    typedef long long ll;
    typedef long double ld;

    using u64 = uint64_t;

    const int MAXN = -1;

    using namespace std;

    int tests;

    int main()
    {
        #ifdef GG
            freopen("../input.txt", "r", stdin);
        #endif
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        cin >> tests;

        while (tests--)
        {
            ll n; cin >> n;
            ll b[n]; forn(i,n) cin >> b[i];

            map<ll,vector<ll>> m;
            forn(i,n)
            {
                m[b[i]].pb(i);
            }

            if (m.begin()->fst != 0) {
                cout << -1 << nl;
                continue;
            }

            ll a[n];
            ll val_anterior = 0;
            bool flag = true;
            auto aux = m.begin();
            ll sombra_anterior = (*aux).fst;
            vector<ll> pos = (*aux).snd;
            aux++;
            for (auto it = aux; it != m.end(); it++) {
                ll sombra = (*it).fst;
                ll val = (sombra - sombra_anterior) / pos.size();
                if(val_anterior >= val) {flag = false; break;}

                ll res = (sombra - sombra_anterior) % pos.size();
                if(res != 0) {flag = false; break;}

                forn(i,pos.size()) a[pos[i]] = val;

                sombra_anterior = (*it).fst;
                val_anterior = val;
                pos = (*it).snd;
            }

            if(!flag)
            {
                cout << -1 << nl;
                continue;
            }

            auto last = m.end();
            last--;
            pos = (*last).snd;
            forn(i,pos.size())
            {
                a[pos[i]] = val_anterior+1;
            }

            forn(i,n)
            {
                cout << a[i] << " ";
            }
            cout << nl;

        }
        
        return 0;
    }