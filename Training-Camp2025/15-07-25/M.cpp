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
const double EPS = 1e-10;

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
    
    int n; cin >> n;
    int b[n];
    forn(i,n)
    {
        cin >> b[i];
    }

    vector<ll> digits(1000);

    int d = 0;
    ll bi = b[0];
    while (bi != 0)
    {
        int inc = min(9-digits[d],bi);
        digits[d] += inc;
        bi -= inc;
        d++;
    }
    int last_digit = d - 1;

    dforn(j, last_digit+1) {
        cout << digits[j];
    }
    cout << nl;

    forr(i,1,n)
    {
        bi = b[i] - b[i-1];
        if (bi == 0)
        {
            int j = 0;
            while (digits[j] == 9)
            {
                bi += 9;
                digits[j] = 0;
                j++;
            }
            digits[j] += 1;
            j > last_digit ? last_digit = j : last_digit = last_digit;
            bi--;
        }
        
        if(bi < 0)
        {
            d = 0;
            while (bi < 0)
            {
                int inc = digits[d]-1;
                digits[d] = 0;
                d++;
                while (digits[d] == 9)
                {
                    digits[d] = 0;
                    inc += 9;
                    d++;
                }
                d > last_digit ? last_digit = d : last_digit = last_digit;
                digits[d] += 1;
                bi += inc;
            }
        }

        d = 0;
        while (bi != 0)
        {
            int inc = min(9-digits[d],bi);
            digits[d] += inc;
            bi -= inc;
            if (d > last_digit)
            {
                last_digit++;
                if (bi != 0)
                {
                    digits[last_digit] = 1;
                    forn(j,last_digit)
                    {
                        digits[j] = 0;
                    }
                    bi = b[i] - 1;
                    d = 0;
                }
            }
            d++;
        }
        
        dforn(j, last_digit+1) {
            cout << digits[j];
        }
        cout << nl;
    }

    return 0;
}
