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

const int MAXN = 1e9 + 9;

using namespace std;
 
int tests;
vector<pair<ll,ll>> deals;

ll pot(ll x, int n) {
    if (n <= 0) return 1;
    if (n == 1) return x;
    if (n % 2 == 0) return pot(x*x, n/2);
    return x * pot(x, n - 1);
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    ll deal = 1;
    int i = 1;
    while (deal <= 1e9)
    {
        deal = pot(3,i-1);
        deals.pb({deal,pot(3,i) + (i-1)*pot(3,i-2)});
        i++;
    }

    while (tests--)
    {
        int n; cin >> n;
        int i = deals.size();
        ll res = 0;
        //ll tratos = 0;
        while (i > 0)
        {
            while (n-deals[i-1].first >= 0)
            {
                n-=deals[i-1].first;
                res += deals[i-1].second;
                //tratos++;
            }
            i--;
        }
        cout << res << nl;
        //cout << tratos << nl;
    }
    
    return 0;
}