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

    const int MAXN = -1;

    using namespace std;
    
    int tests;

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
            int n,m; cin >> n >> m;
            
            priority_queue<int> impares, pares;
            forn(i,n)
            {
                int a; cin >> a;
                if((i+1)%2 == 1) impares.push(a);
                else pares.push(a);
            }

            bool par_used = false;
            bool impar_used = false;

            forn(i,m)
            {
                int x; cin >> x;
                if(x%2 == 1 && !impares.empty())
                { 
                    int e = impares.top();
                    if(e >= 0 || !impar_used) impares.pop();
                    if(!impar_used) impar_used = true;
                }
                else if (x%2 == 0 && !pares.empty())
                { 
                    int e = pares.top();
                    if(e >= 0 || !par_used) pares.pop();
                    if(!par_used) par_used = true;

                }
            }

            ll ans = 0;
            while (!impares.empty())
            {
                int e = impares.top();
                impares.pop();
                ans += e;
            }
            while (!pares.empty())
            {
                int e = pares.top();
                pares.pop();
                ans += e;
            }
            
            cout << ans << nl;
        }
        
        return 0;
    }