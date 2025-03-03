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

const int MAXN = 3*1e5 + 3;

using namespace std;
 
int tests,n,k;
int a[MAXN];
string s;

bool can_paint(int x)
{
    vector<char> t;
    forn(i,n)
    {
        if (a[i] > x)
        {
            t.pb(s[i]);
        }
    }

    int i = 0;
    int blue_parts = 0;
    while (i<t.size())
    {
        while (i<t.size() && t[i] == 'R')
        {
            i++;
        }
        if (i!=t.size())
            blue_parts++;
        while (i<t.size() && t[i] == 'B')
        {
            i++;
        }
    }

    return blue_parts <= k;
}

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
        cin >> n >> k;
        cin >> s;
        int penalty[n+1];
        penalty[n] = 0;
        forn(i,n)
        {
            cin >> a[i];
            penalty[i] = a[i];
        }

        sort(penalty,penalty+n+1);

        int lo = 0, hi = n, ans = INT_MAX;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (can_paint(penalty[mid])) {
                ans = min(ans, penalty[mid]);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << nl;
    }
    
    return 0;
}