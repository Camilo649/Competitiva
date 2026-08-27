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
        int n; cin >> n;
        int a[n]; forn(i,n) cin >> a[i];

        int i = 0;
        int T = 0;
        ll acum = 0;
        
        while (i<n)
        {
            int mn = 1e9, mx = 0;

            while (i<n-1 && a[i] <= a[i+1])
            {
                i++;
            }
            
            mx = a[i];

            forr(j,i+1,n)
            {
                mn = min(mn, a[j]);
                if(a[j] > mx) 
                {
                    i = j-1;
                    break;
                }
            }

            int diff = mx-mn;
            while(acum < diff)
            {
                T++;
                acum += 1<<(T-1);
            }

            i++;
        }

        cout << T << nl;

    }
    
    return 0;
}