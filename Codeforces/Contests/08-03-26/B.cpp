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
        int n,m,l; cin >> n >> m >> l;
        int a[n]; forn(i,n) cin >> a[i];

        m = min(m,n+1);
        vector<int> d(m,0);

        int flash_idx = 0;
        forr(i,1,l+1)
        {
            int mn = 1e9 + 2;
            int mn_idx = -1;
            forn(j,d.size())
            {
                if(d[j] < mn)
                {
                    mn = d[j];
                    mn_idx = j;
                }
            }
            d[mn_idx]++;

            if(i == a[flash_idx])
            {
                int mx = 0;
                int mx_idx = -1;
                forn(j,d.size())
                {
                    if(d[j] > mx)
                    {
                        mx = d[j];
                        mx_idx = j;
                    }
                }
                if(n-flash_idx < m) 
                {
                    d.erase(d.begin() + mx_idx);
                    m--;
                }
                else d[mx_idx] = 0;

                flash_idx = min(flash_idx+1, n-1);
            }

        }

        auto it = max_element(d.begin(), d.end());

        cout << *it << nl;
    }
    
    return 0;
}