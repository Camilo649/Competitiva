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
    cout.tie(0);
    
    cin >> t;

    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        forn(i, n) {
            forn(j, m) {
                cin >> a[i][j];
            }
        }

        // Ordenar las filas
        forn(i, n) {
            sort(a[i].begin(), a[i].end());
        }

        // forn(i, n) {
        //     forn(j, m) {
        //         cout << a[i][j] << ' ';
        //     }
        //     cout << nl;
        // }

        int p[n];
        if(m>1)
        {
            bool flag = true;
            forn(i,n)
            {
                if (a[i][0] == a[i][1] - n)
                {
                    p[i] = a[i][0];
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                cout << -1 << nl;
            }
            else
            {
                forn(i,n)
                {
                    cout << p[i]+1 << ' ';
                }
                cout << nl;
            } 
        }
        else
        {
            forn(i,n)
            {
                p[a[i][0]] = i;
            }

            forn(i,n)
            {
                cout << p[i]+1 << ' ';
            }
            cout << nl;
        }
    }
    

    return 0;
}