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
        int n,m;
        cin >> n >> m;
        ll a[n], b[m];
        forn(i,n)
        {
            cin >> a[i];
        }
        forn(i,m)
        {
            cin >> b[i];
        }

        sort(b, b+m);

        bool flag = true;
        a[0] = min(a[0], b[0]-a[0]);
        forr(i,1,n)
        {
            auto x = lower_bound(b, b+m, a[i-1]+a[i]);
            if (x == b+m)
                *x = b[m-1];
            a[i] = min(a[i], *x - a[i]);
            if (a[i-1] > a[i])
            {
                a[i] = max(a[i], *x - a[i]);
                if (a[i-1] > a[i])
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
        {
            cout << "YES" << nl;
        }
        else
        {
            cout << "NO" << nl;
        }
        
    }
    
    return 0;
}