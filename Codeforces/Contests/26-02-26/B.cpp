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

vector<int> Div;
void getDiv(int n) {
    Div.clear();
    for (int d = 1; d * d <= n; d++) {
        if (n%d == 0) {
            Div.push_back(d);
            Div.push_back(n/d);
        }
        if (d*d == n) Div.pop_back();
    }
    sort(Div.begin(), Div.end()); // OPCIONAL
}

ll expmod(ll b, ll e, int M) {
    ll val = 1;
    b %= M;
    while (e > 0) {
        if (e & 1) val = val * b % M;
        b = b * b % M;
        e >>= 1;
    }
    return val;
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

    while (tests--)
    {
        int x; cin >> x;

        getDiv(x);

        forn(i,Div.size())
        {
            if(expmod((ll)Div[i], x, x)%x == 0)
            {
                cout << Div[i] << nl;
                break;
            }
        }
    }
    
    return 0;
}