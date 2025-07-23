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
        int n;
        cin >> n;
        vector <ll> v;
        multiset<ll> apariciones;
        forn(i,n){
            ll a;
            cin >> a;
            v.pb(a);
            apariciones.insert(a);
        }
        
        int mx = -1e6;
        int mx_pos;
        ll OR;
        forn(i,n) {
            int val = apariciones.count(v[i]) - __builtin_popcountll(v[i]);
            if (val > mx)
            {
                mx = val;
                OR = v[i];
                mx_pos = i;
            }
        }
        
        apariciones.erase(v[mx_pos]);
        int res = mx;
        forn(i,n) {
            int new_ones = __builtin_popcountll(OR | v[i]) - __builtin_popcountll(OR);
            int val = apariciones.count(v[i]) - new_ones;
            if (val >= 0)
            {
                res += val;
                OR |= v[i];
                apariciones.erase(v[i]);
            }
        }

        cout << max(res, 0) << nl;
    }
    
    return 0;
}