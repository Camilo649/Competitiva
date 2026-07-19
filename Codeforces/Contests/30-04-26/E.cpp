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

const int MAXN = 2e5 + 6;

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
        int n; cin >> n;
        int a[n]; forn(i,n) cin >> a[i];

        int mx = 0;
        int mn = MAXN; 
        forn(i,n) 
        {
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }

        vector<int> rights(n+1);
        forn(i,n) rights[a[i]] = i;

        vector<int> gaps(n+1);
        forr(i,a[n-1]+1,mx+1) gaps[i] = n-1;
        int prev = a[n-1];
        int i = n-2;
        while (i>=0)
        {
            while (i>=0 && a[i] >= prev) i--;
            if(i >= 0)
            {
                forr(j,a[i]+1,prev+1) gaps[j] = i;
                prev = a[i];
            } 
        }
        gaps[1] = 0;

        ll total = 0;
        dforr(i,1,n)
        {
            total += max(0, a[i-1]-a[i]);
            if(a[i-1] > a[i]) a[i-1] = a[i];
        }

        ll gan = 0;
        forr(j,1,mx+1)
        {
            int offset = j == mn ? 0 : -1;
            gan = max(gan, (ll)(rights[j]-gaps[j]+offset));
        }

        cout << total + gan << nl;
    }
    
    return 0;
}