#include<bits/stdc++.h>

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
#define CAM
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int t;

int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;

        ll a[n];
        ll mx = 0;
        forn(i,n){
            cin >> a[i];
            mx = max(mx,a[i]);
        }

        forn(i,n) {
            if (a[i] == mx) continue;

            int dif = (mx - a[i])/k;
            if (dif%2==1) dif++;
            a[i] += dif*k;
        }

        ll mn = 1e9;
        forn(i,n){
            mx = max(mx,a[i]);
            mn = min(mn,a[i]);
        }

        if((mx-mn)<k) {
            cout << mx << nl;
        }
        else
        {
            cout << -1 << nl;
        }
    }
    

    return 0;
}