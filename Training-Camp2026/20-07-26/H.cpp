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
#define GE
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

int main()
{
    #ifdef GE
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n,k; cin >> n >> k;
        int a[n]; forn(i,n) cin >> a[i];

        map<int,int> m;
        forn(i,n) 
        {
            if(m.count(a[i]) == 0) m[a[i]] = 0;
            m[a[i]]++;   
        }

        if(m.size() > k)
        {
            cout << -1;
        }
        else
        {
            vector<int> nums;
            for (auto [key, value] : m) {
                nums.pb(key);
            }

            vector<int> res;
            forn(i,n)
            {
                forn(j, k)
                {
                    res.pb(nums[j%nums.size()]);
                }
            }

            cout << res.size() << nl;
            forn(i,res.size())
            {
                cout << res[i] << " ";
            }
        }

        cout << nl;
    }
    
    return 0;
}