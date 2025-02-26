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
        forn(i,n)
        {
            cin >> a[i];
        }

        int l = 0, r = 0;
        int max_inv = 0;
        forn(i,n)
        {
            int inv = 0;
            forr(j,i+1,n)
            {
                if (a[i] > a[j])
                    inv++;
                else if (a[i] < a[j])
                    inv--;

                if (inv > max_inv)
                {
                    l = i;
                    r = j;
                    max_inv = inv;
                }
            }
        }

        if (max_inv == 0)
        {
            cout << 1 << ' ' << 1 << nl;
        }
        
        else
        {
            cout << l+1 << ' ' << r+1 << nl;
        }
    }
    
    return 0;
}