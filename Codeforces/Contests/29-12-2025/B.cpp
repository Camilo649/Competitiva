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
        unsigned int a,b; cin >> a >> b;
        
        int bmx = max(32 - __builtin_clz(a), 32 - __builtin_clz(b));
        int bmn = min(32 - __builtin_clz(a), 32 - __builtin_clz(b));
        int mx = max(a,b);
        int mn = min(a,b);

        if(bmx == bmn) {
            dforn(i,bmn)
            {
                mx -= 1<<i;
                i--;
                if(i>=0) mn -= 1<<i;
            }
            if(mx<0 || mn <0) cout << bmn-1;
            else cout << bmn;
        }
        else
        {
            dforn(i,bmn+1)
            {
                mx -= 1<<i;
                i--;
                if(i>=0) mn -= 1<<i;
            }
            if(mx<0 || mn <0) cout << bmn;
            else cout << bmn+1;
        }

        cout << nl;
    }
    
    return 0;
}