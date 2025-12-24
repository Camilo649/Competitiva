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
    #define nl '\n'
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
            int n,k; cin >> n >> k;
            ll v[n+1] = {};
            int a[n+1]; a[n] = 0;
            forn(i,n)
            {
                cin >> a[i];
                v[a[i]]++;
            }

            bool flag = false;

            forn(i,n+1)
            {
                if(v[i]%k != 0)
                {
                    flag = true;
                    break;
                }
                else
                {
                    v[i] /= k;
                }
            }

            if (flag)
            {
                cout << 0 << nl;
                continue;
            }
            
            int l = 0;
            int r = 0;
            ll score = 0;
            ll count [n+1] = {};
            while (l<n)
            {
                while (r<n && count[a[r]] < v[a[r]])
                {
                    count[a[r]]++;
                    r++;
                }
                score += r-l;
                count[a[l]]--;
                l++;
            }

            cout << score << nl;

        }
        
        return 0;
    }