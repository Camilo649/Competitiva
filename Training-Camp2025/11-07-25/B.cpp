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
        vector<tuple<int,int,int>> v;

        int n; cin >> n;
        forn(i,n)
        {
            int a,b,c; cin >> a >> b >> c;
            v.pb({a,b,c});
        }

        unordered_map<int, int> x, y, z;
        for (auto [a,b,c] : v) {
            x[a]++;
            y[b]++;
            z[c]++;
        }

        vector<int> d;
        forn(i,n)
        {
            int a,b,c;
            a = x[get<0>(v[i])];
            b = y[get<1>(v[i])];
            c = z[get<2>(v[i])];
            a--; b--; c--;
            d.pb(max({a,b,c}));
        }
        sort(d.begin(), d.end());

        int count = 0;
        forn(k,n)
        {
            while (count < n && d[count] < k)
            {
                count++;
            }
            cout << count << " ";
        }
        cout << nl;
    }
    
    return 0;
}