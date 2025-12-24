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
        string n; cin >> n;
        ll num = 0;
        forn(i,n.size())
        {
            ll aux = n[i] - '0';
            forn(j,n.size()-(i+1)) aux *= 10;
            num += aux;
        }

        set<ll> res;
        ll exp = 10;
        forn(i,n.size())
        {
            if (num % (exp+1) == 0) res.insert(num/(exp+1));
            exp *= 10;
        }
        
        cout << res.size() << nl;
        for (auto r : res)
        {
            cout << r << " ";
        }
        if(res.size() != 0) cout << nl;
    }
    
    return 0;
}