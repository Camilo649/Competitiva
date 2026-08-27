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
const int INF = 1e9;

using namespace std;
 
int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int r,c,k; cin >> r >> c >> k;

        string g[r];
        int rice_count = 0;
        forn(i,r)
        {
            cin >> g[i];
            forn(j,c)
            {
                if(g[i][j] == 'R') rice_count++;
            }
        }

        // forn(i,r)
        // {
        //     cout << g[i] << nl;
        // }

        int rice_per_chicken[k];
        forn(i,k) rice_per_chicken[i] = rice_count/k;
        int resto = rice_count % k;
        forn(i,resto) rice_per_chicken[i]++;
        rice_per_chicken[k-1] += INF;

        int chicken = 0;
        forn(i,r)
        {
            if(i%2 == 0)
            {
                forn(j,c)
                {
                    if(g[i][j] == 'R') rice_per_chicken[chicken]--;
                    if(chicken <= 9) g[i][j] = '0' + chicken;
                    else if((chicken > 9 && chicken <= 9+26)) g[i][j] = 'A' + (chicken-10);
                    else g[i][j] = 'a' + (chicken-(10+26));
                    if(rice_per_chicken[chicken] == 0)
                    {
                        chicken++;
                    }
                        
                }
            }
            else
            {
                dforn(j,c)
                {
                    if(g[i][j] == 'R') rice_per_chicken[chicken]--;
                    if(chicken <= 9) g[i][j] = '0' + chicken;
                    else if((chicken > 9 && chicken <= 9+26)) g[i][j] = 'A' + (chicken-10);
                    else g[i][j] = 'a' + (chicken-(10+26));
                    if(rice_per_chicken[chicken] == 0)
                    {
                        chicken++;
                    }
                        
                }
            }
        }

        forn(i,r)
        {
            cout << g[i];
            cout << nl;
        }
    }    

    return 0;
}