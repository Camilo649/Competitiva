#include<bits/stdc++.h>

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
 
int t;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        ll psum = 0, osum = 0;

        forn(i,n)
        {
            cin >> a[i];
            if (i%2 == 0)
                psum += a[i];
            else
                osum += a[i];
        }

        int ocount = n/2;
        int pcount = n - ocount;

        if (psum%pcount != 0 || osum%ocount != 0 || (psum+osum)%n != 0)
        {
            cout << "NO" << nl;
        }
        else if (n == 3 && (a[0]+a[2])/2 != a[1])
        {
            cout << "NO" << nl;
        }
        else if (n%2 == 0 && psum != osum)
        {
            cout << "NO" << nl;
        }
        else
        {
            cout << "YES" << nl;
        }
    }
    

    return 0;
}