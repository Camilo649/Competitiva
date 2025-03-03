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
        ll n,x,k;
        cin >> n >> x >> k;
        string s;
        cin >> s;

        forn(i,n)
        {
            if (s[i] == 'L')
            {
                x--;
            }
            else
            {
                x++;
            }
            
            if (x==0)
            {
                k-=(i+1);
                break;
            }
        }

        if (x != 0)
        {
            cout << 0 << nl;
        }
        else
        {
            ll steps = 0, res = 1;
            ll lcount = 0, rcount = 0;
            forn(i,n)
            {
                if (s[i] == 'L')
                {
                    lcount++;
                }
                else
                {
                    rcount++;
                }
    
                if (lcount == rcount)
                {
                    steps = i+1;
                    break;
                }
            }
    
            steps == 0 ? res = res : res += k/steps;
    
            cout << res << nl;
        }
    }
    
    return 0;
}