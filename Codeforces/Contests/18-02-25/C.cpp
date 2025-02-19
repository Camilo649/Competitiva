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

    const ll MAXN = 998244353;

    using namespace std;
    
    int tests;

    ll powmod(ll base, ll exp, ll mod) {
        ll val = 1;
        while (exp > 0) {
            if (exp & 1) val = val * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return val;
    }

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
            int n;
            cin >> n;
            int a[n];
            forn(i,n)
            {
                cin >> a[i];
            }

            ll res = 0;
            int i = 0;
            while (i<n && a[i] != 1)
            {
                i++;
            }
            int m = n-1;
            while(m>i && a[m] != 3)
            {
                m--;
            }
            
            int count1 = 0;
            int j = i;
            while(j<=m)
            {
                if (a[j] == 1)
                {
                    count1++;
                }
                j++;
            }

            int count2 = 0, count3 = 0;
            while(i<=m)
            {
                if (a[m] == 1)
                {
                    res += count1*(powmod(2,count2,MAXN) - 1);
                    count2 = 0;
                    count3 = 0;
                    count1--;
                }
                else if (a[m] == 2)
                {
                    count2++;
                }
                m--;
            }

            cout << res << nl;
            
        }
        
        return 0;
    }