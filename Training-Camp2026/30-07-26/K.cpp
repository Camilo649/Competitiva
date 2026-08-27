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
        
        string s; cin >> s;

        int n = s.size();
        ld sum = 0.0;
        forn(i,n)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int j = i;
                while (j<n && ((s[j] >= '0' && s[j] <= '9') || (s[j] == '.'))) j++;
                bool point = true;
                string t;
                int count = 0;
                dforr(k,i,j)
                {   
                    count++;
                    if(s[k] != '.' || (point && count == 3))
                    {
                        t+= s[k];
                    }
                    if(t[k] == '.') point = false;
                }
                reverse(t.begin(), t.end());
                ld price = stold(t);
                sum += price;
                i = j-1;
            }
        }

        string aux = to_string(sum);
        string res;

        int j = aux.size()-1;
        while (aux[j] != '.')
        {
            j--;
        }
        //j++;

        dforr(i,j,j+3)
        {
            res += aux[i];
        }

        int count = 0;
        dforr(i,0, aux.size()-3)
        {
            res += aux[i];
            count++;
            if(count%3 == 0) aux += '.';
        }

        reverse(res.begin(), res.end());

        cout << res << nl;
        
        return 0;
    }