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
const ll INF = 1e10;

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
        ll n,c; cin >> n >> c;
        vector<ll> a;
        forn(i,n)
        {
            ll val;
            cin >> val;
            a.pb(val);
        }

        sort(a.begin(), a.end());

        int count = 0;
        while (a[0] <= c)
        {
            int i = 1;
            while (a[i] <= c && i < n)
            {
                i++;
            }
            i--;
            count++;
            forn(j, n)
            {
                if (j != i && a[j] <= c)
                {
                    a[j] *= 2;
                }
                else
                {
                    a[j] = c+1;
                }
            }
        }

        cout << n - count << nl;
    }
    
    return 0;
}