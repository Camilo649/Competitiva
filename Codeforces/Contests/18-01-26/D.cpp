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
        int n,m,h; cin >> n >> m >> h;
        vector <ll> a;
        //ll sum[n] = {};
        forn(i,n)
        { 
            int v;
            cin >> v;
            a.pb(v);
        }
        vector <ll> b = a;

        set<int> s;
        forn(j,m)
        {
            ll i,val; cin >> i >> val;
            i--;
            if(s.count(i) == 0)
            {
                a[i] = b[i];
                s.insert(i);
            }
            a[i] += val;
            if(a[i] > h)
            {
                s.clear();
            }
        }

        forn(i,n)
        {
            if(s.count(i) == 0) a[i] = b[i];
        }

        forn(i,n)
        {
            cout << a[i] << " ";
        }
        cout << nl;
    }
    
    return 0;
}