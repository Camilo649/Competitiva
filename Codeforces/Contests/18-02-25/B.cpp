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
        int n,m;
        cin >> n >> m;
        int a[n+2][m+2] = {};
        unordered_map<int,bool> c;
        forr(i,1,n+1)
        {
            forr(j,1,m+1)
            {
                cin >> a[i][j];
            }
        }

        // forr(i,0,n+2)
        // {
        //     forr(j,0,m+2)
        //     {
        //         cout << a[i][j] << ' ';
        //     }
        //     cout << nl;
        // }

        forr(i,1,n+1)
        {
            forr(j,1,m+1)
            {
                if (c.count(a[i][j]) == 0)
                    c[a[i][j]] = true;
                c[a[i][j]] &= (a[i][j] != a[i+1][j]) && (a[i][j] != a[i-1][j]) && (a[i][j] != a[i][j+1]) && (a[i][j] != a[i][j-1]);
            }
        }

        int steps = 0;
        int flag = false;
        for (auto [key, value] : c)
        {
            if(value == false)
            {
                steps += 2;
                flag = true;
            }
            else
            {
                steps += 1;
            }
        }

        if (flag)
        {
            cout << steps-2 << nl;
        }
        else
        {
            cout << steps-1 << nl;
        } 
    }
    
    return 0;
}