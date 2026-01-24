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
        ll n; cin >> n;
        ll x; cin >> x;
        ll a[n], b[n], c[n];
        forn(i,n)
        {
            cin >> a[i] >> b[i] >> c[i];
        }

        ll best = -1;
        ll best_id = -1;
        bool flag = false;
        forn(i,n)
        {
            if(a[i]*(b[i]-1) >= x)
            {
                flag = true;
                break;
            }
            if(b[i] > 1) x -= a[i]*(b[i]-1);
            if(a[i]*b[i] - c[i] > best)
            {
                best = a[i]*b[i] - c[i];
                best_id = i;
            }
            else if(a[i]*b[i] - c[i] == best)
            {
                if(a[i]*(b[i]-1) > a[best_id]*(b[best_id]-1))
                {
                    best = a[i]*b[i] - c[i];
                    best_id = i;
                }
            }
        }
        //x += a[best_id]*(b[best_id]-1);

        if(flag) cout << 0;
        else if(best <= 0) cout << -1;
        else cout << ((x+best-1)/best);
        cout << nl;
    }
    
    return 0;
}