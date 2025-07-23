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
typedef __int128 ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

map<ll, ll> F;
void fact(ll n) {
    F.clear();
    for (ll p = 2; p * p <= n; p++) {
        while (n%p == 0) {
            F[p]++;
            n /= p;
        }
    }
    if (n > 1) F[n]++;
}

ll mcd(ll a, ll b) {
    if (b == 0) return a;
    return mcd(b, a%b);
}

int main()
{
    #ifdef MILF
    //    freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        long long P,Q; cin>>P>>Q;
        ll p,q;
        p=P;
        q=Q;
        //cin >> p >> q;
        if (p%q != 0)
        {
            string sres = to_string((long long)p);
            cout << sres << nl;
        }
        else
        {
            fact(q);
            ll mx = 1;
            for(auto f : F)
            {
                ll exp = 0;
                ll res = p;
                ll val = 1;
                forr(i,1, 40)
                {
                    val*=f.first;
                    if(p%val != 0) break;
                    exp = i;
                }
                //cout << f.first << ": " << exp << nl;
                //exp != f.second ? exp = max(exp - (f.second+1), (ll)0) : exp = exp; 
                //cout << exp << nl;
                exp -= f.second;
                exp++;
                val = 1;
                forr(i,1,exp+1) val*=f.first;
                res/=val;
                mx = max(mx, res);
            }
            string sres = to_string((long long)mx);
            cout << sres << nl;
        }
    }
    
    return 0;
}