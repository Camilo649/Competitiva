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
        int n,k;
        cin >> n >> k;
        int a[n];
        forn(i,n)
        {
            cin >> a[i];
        }

        bool flag;
        int index;
        forn(i,n)
        {
            flag = true;
            forn(j,n)
            {
                if (i==j)
                {
                    continue;
                }
                flag = flag && abs(a[i]-a[j])%k != 0;
            }
            if (flag)
            {
                index = i+1;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << nl;
            cout << index << nl;
        }
        else
        {
            cout << "NO" << nl;
        }
    }
    
    return 0;
}