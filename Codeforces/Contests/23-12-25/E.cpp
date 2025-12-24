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
        int n,x,y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        int p[n];
        forn(i,n) cin >> p[i];
        bool flag = true;

        // ll sump = 0;
        // forn(i,n)
        // {
        //     sump += p[i];
        // }
        // if (sump > x+y) flag = false;

        ll difa = 0;
        ll difb = 0;
        forn(i,n)
        {
            if (s[i] == '0')
            {
                if (p[i]%2 == 0)
                {
                    difa += 2;
                }
                else
                {
                    difa += 1;
                }
            }
            else
            {
                if (p[i]%2 == 0)
                {
                    difb += 2;
                }
                else
                {
                    difb += 1;
                }
            }
        }
        forn(i,n)
        {
            ll a,b;
            if (s[i] == '0')
            {
                if(p[i]%2 == 0) difa -= 2;
                else difa -= 1;
                a = min(((ll)p[i]/2) + 1, (ll)x-difa);
                b = p[i] - a;
                if(a<=b) flag = false;
            }
            else
            {
                if(p[i]%2 == 0) difb -= 2;
                else difb -= 1;
                b = min(((ll)p[i]/2) + 1, (ll)y-difb);
                a = p[i] - b;
                if(b<=a) flag = false;
            }
            x -= a;
            y -= b;
        }
        if(s[n-1] == '0' && x < y) flag = false;
        if(s[n-1] == '1' && y < x) flag = false;

        if(flag)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << nl;
    }
    
    return 0;
}