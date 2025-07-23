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
const double EPS = 1e-10;

using namespace std;
 
int tests;

vector<pair<int, int>> F;
void fact(ll n) {
    F.clear();
    for (ll p = 2; p * p <= n; p++) {
        int k = 0;
        while (n%p == 0) {
            k++;
            n /= p;
        }
        F.pb({p,k});
    }
    if (n > 1) F.pb({n,1});
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    
    cin >> tests;

    while (tests--)
    {
        ll n; cin >> n;
        fact(n);
        ll sum[F.size()+1];
        sum[0] = 0;
        int res = 1;
        int i = 1;
        for (auto p : F)
        {
            res *= (p.second+1);
            sum[i] = sum[i-1] + p.second;
            i++;
        }

        forn(i,F.size())
        {
            res += sum[i+1]*(sum[F.size()]-sum[i+1]);  
        }

        cout << res << nl;
    }
    
    return 0;
}