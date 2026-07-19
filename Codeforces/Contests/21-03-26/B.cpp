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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        int a[n]; forn(i,n) cin >> a[i];

        vector<int> ans;
        forn(i,n-1)
        {
            int l = 0, g = 0;
            forr(j,i+1,n)
            {
                if(a[j] < a[i]) l++;
                if(a[j] > a[i]) g++;
            }
            ans.pb(max(l,g));
        }
        ans.pb(0);

        forn(i,n)
        {
            cout << ans[i] << " ";
        }
        cout << nl;
    }
    
    return 0;
}