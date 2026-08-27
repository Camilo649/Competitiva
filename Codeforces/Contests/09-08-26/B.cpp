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

    const ll M = 998244353;

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
            int n; cin >> n;
            string s; cin >> s;

            for(int i = 0; i<n; i+=2)
            {
                if(s[i] != '?')
                {
                    char c = s[i];
                    for(int j = i+2; j<n; j += 2)
                    {
                        if(c == '1') c = '0';
                        else c = '1';

                        if(s[j] == '?') s[j] = c;
                    }

                    c = s[i];
                    for(int j = i-2; j>=0; j -= 2)
                    {
                        if(c == '1') c = '0';
                        else c = '1';

                        if(s[j] == '?') s[j] = c;
                    }

                    break;
                }
            }

            for(int i = 1; i<n; i+=2)
            {
                if(s[i] != '?')
                {
                    char c = s[i];
                    for(int j = i+2; j<n; j += 2)
                    {
                        if(c == '1') c = '0';
                        else c = '1';

                        if(s[j] == '?') s[j] = c;
                    }

                    c = s[i];
                    for(int j = i-2; j>=0; j -= 2)
                    {
                        if(c == '1') c = '0';
                        else c = '1';

                        if(s[j] == '?') s[j] = c;
                    }

                     break;
                }
            }

            //cout << s << nl

            bool flag4 = true;
            forn(i,n)
            {
                flag4 &= s[i] == '?'; 
            }

            bool flag0 = false;
            forr(i,1,n-1)
            {
                flag0 |= ((s[i-1] == '0' && s[i+1] == '0') || (s[i-1] == '1' && s[i+1] == '1')); 
            }

            bool flag1 = true;
            forn(i,n)
            {
                flag1 &= s[i] != '?'; 
            }

            if(flag4) cout << 4 << nl
            else if(flag0) cout << 0 << nl
            else if(flag1) cout << 1 << nl
            else cout << 2 << nl
        }
        
        return 0;
    }