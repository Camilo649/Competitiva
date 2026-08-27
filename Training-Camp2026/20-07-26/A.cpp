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
#define GE
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e5 + 5;

using namespace std;
 
int tests;

int main()
{
    #ifdef GE
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        vector<int> g[n];
        forn(i,n)
        {
            int k; cin >> k;
            forn(j,k)
            {
                int aux; cin >> aux;
                g[i].pb(aux);
            }
        }

        int polycarp_res = 0;
        bitset<MAXN> marked_f; // Principes marcados
        bitset<MAXN> marked_g; // Princesas marcadas
        forn(i,n)
        {
            forn(j,g[i].size())
            {
                if(!marked_f[g[i][j]-1])
                {
                    marked_f[g[i][j]-1] = 1;
                    marked_g[i] = 1;
                    polycarp_res++;
                    break;
                }
            }
        }

        pair<int,int> res = {0,0};
        bool flag = false;
        forn(i,n)
        {
            if(!marked_g[i])
            {
                forn(j,n)
                {
                    if(!marked_f[j])
                    {
                        res = {i+1,j+1};
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) break;
        }

        // cout << "PRINCESAS" << nl;
        // forn(i,n)
        // {
        //     forn(j,g[i].size())
        //     {
        //         cout << g[i][j] << " ";
        //     }
        //     cout << nl;
        // }

        // cout << "PRINCIPES" << nl;
        // forn(i,n)
        // {
        //     forn(j,f[i].size())
        //     {
        //         cout << f[i][j] << " ";
        //     }
        //     cout << nl;
        // }

        if(res.fst == 0 && res.snd == 0)
        {
            cout << "OPTIMAL" << nl;
        }
        else
        {
            cout << "IMPROVE" << nl;
            cout << res.fst << " " << res.snd << nl;
        }
    }
    
    return 0;
}