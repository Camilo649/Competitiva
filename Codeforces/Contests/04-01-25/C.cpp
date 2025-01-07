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
        ll l,r;
        cin >> l >> r;

        int shift = 30; 
        while (!(r&1<<shift))
        {
            shift--;
        }

        ll a = r, b = 0, c = 0;
        forn(i,shift+1)
        {
            if (!(a&1<<i))
            {
                b += 1<<i;
            }
        }
        int i = 0;
        while ((b<l || b>r) && i<=shift)
        {
            if (b<l)
            {
                if (!(b&1<<i))
                {
                    b += 1<<i;
                }
            }
            if (b>r)
            {
                if (b&1<<i)
                {
                    b -= 1<<i;
                }
            }
            i++;
        }
        c = b;
        forn(i,shift+1)
        {
            if (b&1<<i)
            {
                c -= 1<<i;
            }
            else
            {
                c += 1<<i;
            }
            if(c>=l && c<r)
                break;
            else
            {
                if (c<l)
                {
                    if (!(c&1<<i))
                    {
                        c += 1<<i;
                    }
                }
                if (c>=r)
                {
                    if (c&1<<i)
                    {
                        c -= 1<<i;
                    }
                }
            }  
        }

        cout << a << ' ' << b << ' ' << c << nl;
    }
    
    
    
    

    return 0;
}