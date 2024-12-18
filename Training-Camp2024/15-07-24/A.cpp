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
#define MAT
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int t,a,b,c,x,y;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> x >> y;

        int r1 = a-x;
        int r2 = b-y;

        if (r1 < 0)
        {
            c -= abs(r1);
        }
        if (r2 < 0)
        {
            c -= abs(r2);
        }
        
        if (c < 0)
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