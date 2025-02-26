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
            vector<int> dp(4, 0);
            dp[0] = 1;
            while (n--) {
              int x;
              cin >> x;
              if (x == 2) dp[x] = (dp[x] + dp[x]) % MAXN;
              dp[x] = (dp[x] + dp[x-1]) % MAXN;
            }
            cout << dp[3] << '\n';
            
        }
        
        return 0;
    }