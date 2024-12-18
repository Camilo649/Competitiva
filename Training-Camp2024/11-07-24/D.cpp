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
//#define MAT
// redefiniciones
typedef long int ll;
typedef long double ld;

using u64 = uint64_t;
using namespace std;
const int MAXN = -1;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    ll n, k;
    cin >> n >> k;

    ll kaux = k;
    multiset<ll>s;
    dforn(i, 30) {
        ll e = 1 << i;
        while (((n-e) >= 0) && kaux != 0)
        {
            s.insert(e);
            n -= e;
            --kaux;
        } 
    }

    if ((s.size() > k) || (n != 0))
    {
        cout << "NO" << nl;
    }
    else
    {
        while (s.size() != k)
        {
            auto aux1 = --s.end();
            if (*aux1 == 1)
            {
                cout << "NO" << nl;
                return 0;
            }
            s.erase(aux1);
            ll aux2 = *aux1/2;
            s.insert(aux2);
            s.insert(aux2);
        }
        
        cout << "YES" << nl;
        for (auto e:s)
        {
            cout << e << ' ';
        }
        cout << nl;
    }
    
    

    return 0;
}