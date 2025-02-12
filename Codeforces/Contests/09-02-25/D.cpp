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
        int n,m;
        cin >> n >> m;
        vector<vector<int>> v(n);
        forn(i,n)
        {
            forn(j,m)
            {
                int a;
                cin >> a;
                v[i].push_back(a);
            }
        }

        vector<pair<ll,int>> sum;
        forn(i,n)
        {
            int s = 0;
            forn(j,m)
            {
                s += v[i][j];
            }
            sum.push_back({s,i});
        }

        sort(sum.begin(), sum.end(), [&v](const pair<ll, int>& a, const pair<ll, int>& b) {
            if (a.first != b.first)
                return a.first > b.first;
            return v[a.second][0] > v[b.second][0];
        });

        ll res = 0;
        ll s = 0;
        forn(i,sum.size())
        {
            forn(j,m)
            {
                s += v[sum[i].second][j];
                res += s;
            }
        }

        cout << res << nl;
    }
    
    return 0;
}