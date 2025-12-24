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
        int n;
        cin >> n;
        int a[n];
        forn(i,n) cin >> a[i];

        int mx = 0;
        if(abs(a[0]-a[1]) > mx)
        {
            mx = abs(a[0]-a[1]);
        }
        forn(i,n-2)
        {
            if(abs(a[i]-a[i+1]) + abs(a[i+1]-a[i+2]) - abs(a[i]-a[i+2]) > mx)
            {
                mx = abs(a[i]-a[i+1]) + abs(a[i+1]-a[i+2]) - abs(a[i]-a[i+2]);
            }
        }
        if(abs(a[n-2]-a[n-1]) > mx)
        {
            mx = abs(a[n-2]-a[n-1]);
        }

        //cout << mx << nl;

        int sum = 0;
        forn(i,n-1)
        {
            sum += abs(a[i]-a[i+1]);
        }

        cout << sum-mx << nl;
    }
    
    return 0;
}