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
        int n;
        cin >> n;

        int a[n];
        forn(i,n)
        {
            cin >> a[i];
        }

        bool flag = false;

        forn(i,n-1)
        {
            int x = a[i], y = a[i], z = a[i+1];
            if ((x+y>z) && (y+z>x) && (z+x>y))
            {
                y = a[i+1];
                if ((x+y>z) && (y+z>x) && (z+x>y))
                {
                    cout << "YES" << nl;
                    flag = true;
                    break;
                }
            }
        }

        if (!flag)
        {
            forr(i,1,n-1)
            {
                int x = a[i-1], y = a[i], z = a[i+1];
                if ((x+y>z) && (y+z>x) && (z+x>y))
                {
                    x = a[i-1], y = a[i], z = a[i];
                    if ((x+y>z) && (y+z>x) && (z+x>y))
                    {
                        x = a[i-1], y = a[i+1], z = a[i+1];
                        if ((x+y>z) && (y+z>x) && (z+x>y))
                        {
                            x = a[i], y = a[i-1], z = a[i-1];
                            if ((x+y>z) && (y+z>x) && (z+x>y))
                            {
                                x = a[i], y = a[i+1], z = a[i+1];
                                if ((x+y>z) && (y+z>x) && (z+x>y))
                                {
                                    x = a[i+1], y = a[i-1], z = a[i-1];
                                    if ((x+y>z) && (y+z>x) && (z+x>y))
                                    {
                                        x = a[i+1], y = a[i], z = a[i];
                                        if ((x+y>z) && (y+z>x) && (z+x>y))
                                        {
                                            cout << "YES" << nl;
                                            flag = true;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if(!flag)
        {
            cout << "NO" << nl;
        }

    }
    

    return 0;
}