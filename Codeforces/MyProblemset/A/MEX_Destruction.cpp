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
        int count0 = 0;
        forn(i,n)
        {
            cin >> a[i];
            if (a[i] == 0)
                count0++;
        }

        if (count0 == n)
        {
            cout << 0 << nl;
        }
        else if (count0 == 0)
        {
            cout << 1 << nl;
        }
        else
        {
            int cont0;
            a[0] == 0? cont0 = 1 : cont0 = 0;
            for (int i = 1; i < n; i++)
            {
                if (a[i] == 0 && a[i-1] != 0)
                {
                    cont0++;
                }
            }
            if (cont0 == 1 && (a[0] == 0 || a[n-1] == 0))
            {
                cout << 1 << nl;
            }
            else if (a[0] == 0 && a[n-1] == 0 && cont0 == 2)
            {
                cout << 1 << nl;
            }
            else
            {
                cout << 2 << nl;
            }
        }
    }
    

    return 0;
}