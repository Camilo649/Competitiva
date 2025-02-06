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
 
int t;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;

    while (t--)
    {
        ll n,x,y;
        cin >> n >> x >> y;
        int a[n];
        ll sum = 0;
        forn(i,n)
        {
            cin >> a[i];
            sum += a[i];
        }

        sort(a, a+n);

        ll res = 0;
        forn(i,n)
        {
            auto it_min = lower_bound(a+i+1, a+n, sum-a[i]-y);
            auto it_max = upper_bound(a+i+1, a+n, sum-a[i]-x);
            res += (it_max - it_min);
        }

        cout << res << nl;

    }

    return 0;
}