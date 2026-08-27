#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) sort(x.begin(), x.end())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

vector<ll> Div;
void getDiv(ll n) {
    Div.clear();
    for (ll d = 1; d * d <= n; d++) {
        if (n%d == 0) {
            Div.push_back(d);
            Div.push_back(n/d);
        }
        if (d*d == n) Div.pop_back();
    }
    Div.pb(0);
    sort(Div.begin(), Div.end()); // OPCIONAL
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        ll S,q; cin >> S >> q;
        getDiv(S);

        vector<ll> pref(SZ(Div), 0);
        forr(i, 1, SZ(Div)) {
            ll AreaEscalon = (Div[i] - Div[i-1]) * (S / Div[i]);
            pref[i] = pref[i-1] + AreaEscalon;
        }


        forn(i,q)
        {
            ll x,y; cin >> x >> y;
            auto Dy = upper_bound(Div.begin(), Div.end(), S/y);
            Dy--;
            if(x <= *Dy)
            {
                cout << x*y << nl;
                continue;
            }

            auto Dnext = upper_bound(Div.begin(), Div.end(), x);
            auto Dx = Dnext;
            Dx--;
            int idx_x = Dx - Div.begin();
            int idx_y = Dy - Div.begin();
            ll A1 = (*Dy)*y;
            ll A2 = pref[idx_x] - pref[idx_y];
            ll A3 = 0;
            if (x > *Dx) {
                A3 = (x - *Dx) * (S / *Dnext);
            }
            cout << A1 + A2 + A3 << nl;
        }
    }
    
    return 0;
}