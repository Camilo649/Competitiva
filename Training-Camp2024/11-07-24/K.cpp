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
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;
using namespace std;
const int MAXN = -1;
 
ll n;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> n;
    ll a;
    set<pair<ll, ll>>t;
    forn(i,2*n) {
        cin >> a;
        t.insert(make_pair(a,i));
    }

    ll s,d;
    auto e = t.begin();
    s = e->second;
    t.erase(e);
    e = t.begin();
    d = e->second;
    t.erase(e);

    ll dist = s + d;
    forn(i, n-1) {
        auto aux1 = t.begin();
        auto aux2 = ++t.begin();
        
        ll r1, r2;
        r1 = abs(s - aux1->second) + abs(d - aux2->second);
        r2 = abs(d - aux1->second) + abs(s - aux2->second);
        if (r1 <= r2)
        {
            s = aux1->second;
            d = aux2->second;
            dist += r1;
        }
        else
        {
            d = aux1->second;
            s = aux2->second;
            dist += r2;
        }  
        t.erase(aux2);
        t.erase(aux1);
    }

    cout << dist << nl;

    return 0;
}