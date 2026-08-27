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
    #define GE
    // redefiniciones
    typedef long long ll;
    typedef long double ld;

    using u64 = uint64_t;

    const int MAXN = -1;

    using namespace std;
    
    int tests;

    int main()
    {
        #ifdef GE
            freopen("../input.txt", "r", stdin);
        #endif
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        cin >> tests;

        while (tests--)
        {
            ll d,k; cin >> d >> k;

            pair<ll,ll> p = {0,0};
            bool flag = false;
            while ((p.fst+k)*(p.fst+k) + (p.snd)*(p.snd) <= d*d || (p.fst)*(p.fst) + (p.snd+k)*(p.snd+k) <= d*d)
            {
                if(p.fst <= p.snd) p.fst += k;
                else p.snd += k;
                flag = !flag;
            }

            if(flag) cout << "Ashish";
            else cout << "Utkarsh";
            cout << nl;
        }
        
        return 0;
    }