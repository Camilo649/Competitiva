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
        int n,x,s; cin >> n >> x >> s;
        string u; cin >> u;

        vector<int> next;
        forn(i,n) if(u[i] == 'I' || u[i] == 'A') next.pb(i);
        int free = 0;
        int res = 0;
        int m = next.size();
        forn(i,n)
        {
            if(u[i] == 'E')
            {
                if(free > 0)
                {
                    res++;free--;
                }
            }
            else if (u[i] == 'I')
            {
                if(x>0)
                {
                    res++;x--;free+=s-1;
                }
                m--;
            }
            else
            {
                auto p = upper_bound(next.begin(), next.end(), i);
                int dist = (p == next.end()) ? (n-i) : (*p - i);
                if(dist <= free && x<m)
                {
                    res++;free--;
                }
                else if(x>0)
                {
                    res++;x--;free+=s-1;
                }
                m--;
            }
        }

        cout << res << nl;
    }
    
    return 0;
}