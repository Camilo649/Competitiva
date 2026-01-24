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
        int n,h,l; cin >> n >> h >> l;
        int a[n]; forn(i,n) cin >> a[i];

        sort(a, a+n);

        int mn = min(h,l);
        int mx = max(h,l);
        int left = 0, r = n-1;
        while(r>0 && (r+1)%2 == 1 && a[r]>mx)
        {
            r--;
        }

        int ans = 0;
        while (left<r)
        {
            if(a[left]<=mn && a[r]<=mx) 
            {
                ans++;
                left++; r--;
            }
            else r--;
        }
        
        cout << ans << nl;
    }
    
    return 0;
}