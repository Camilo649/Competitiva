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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int a[200][200], aux[200][200];
int n,m;
int pos = 0;

bool check()
{
    int count = 0;
    forn(i,n)
    {
        forn(j,m-1)
        {
            if(a[i][j] != a[i][j+1]) 
            {
                count++;
                pos = i;
            }
        }
    }

    return count <= 1;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    forn(i,n)
    {
        forn(j,m)
        {
            cin >> a[i][j];
        }
    }

    forn(i,n)
    {
        forn(j,m)
        {
            aux[i][j] = a[i][j];
        }
    }


    vector<int> columnas_res;
    forn(j,m)
    {
        if(a[0][j] == 1)
        {
            forn(i,n)
            {
                a[i][j] = a[i][j] ^ 1;
            }
            columnas_res.pb(1);
        }
        else
        {
            columnas_res.pb(0);
        }
    }

    if(check())
    {
        cout << "YES" << nl;

        vector<int> filas_res;
        forn(i,n)
        {
            if(i<=pos)
            {
                if(a[i][0] == 0) filas_res.pb(0);
                else filas_res.pb(1);
            }
            else
            {
                if(a[i][1] == 1) filas_res.pb(0);
                else filas_res.pb(1);
            }
        }

        forn(i,n) cout << filas_res[i];
        cout << nl;
        forn(j,m) cout << columnas_res[j];
        cout << nl;

        // forn(i,n)
        // {
        //     forn(j,m)
        //     {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << nl;
        // }
    }
    else
    {
        forn(i,n)
        {
            forn(j,m)
            {
                a[i][j] = aux[i][j];
            }
        }

        columnas_res.clear();
        forn(j,m)
        {
            if(a[1][j] == 1)
            {
                forn(i,n)
                {
                    a[i][j] = a[i][j] ^ 1;
                }
                columnas_res.pb(1);
            }
            else
            {
                columnas_res.pb(0);
            }
        }

        if(check())
        {
            cout << "YES" << nl;

            vector<int> filas_res;
            forn(i,n)
            {
                if(i<=pos)
                {
                    if(a[i][0] == 0) filas_res.pb(0);
                    else filas_res.pb(1);
                }
                else
                {
                    if(a[i][1] == 1) filas_res.pb(0);
                    else filas_res.pb(1);
                }
            }

            forn(i,n) cout << filas_res[i];
            cout << nl;
            forn(j,m) cout << columnas_res[j];
            cout << nl;

            // forn(i,n)
            // {
            //     forn(j,m)
            //     {
            //         cout << a[i][j] << " ";
            //     }
            //     cout << nl;
            // }
        }
        else
        {
            cout << "NO" << nl;
        }
    }
    
    return 0;
}