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
        int n,m; cin >> n >> m;
        ll score = 0;
        int pos = 0;
        ll t = 0;
        forn(i,n)
        {
            int a,b; cin >> a >> b;
            if (pos == b)
            {
                if((a-t)%2 == 0) score += a-t;
                else score += a-1-t;
            }
            else
            {
                if((a-t)%2 == 1) score += a-t;
                else score += a-1-t;
            }
            pos = b;
            t = a;
        }

        cout << score+(m-t) << nl;
    }
    
    return 0;
}