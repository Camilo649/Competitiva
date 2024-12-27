#include<bits/stdc++.h>

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
        vector<int> res;

        int n,d;
        cin >> n >> d;

        res.pb(1);

        if (d%3 == 0 || n >= 3)
            res.pb(3);

        if (d == 5)
            res.pb(5);

        if (d == 7 || n >= 3)
            res.pb(7);   

        if (d == 9 || n >= 6)
            res.pb(9); 
        else
        {
            int fact = 1;
            for (int i = 1; i <= n; i++)
            {
                fact *= i;
            }
            
            int sum = fact * d;
            if (sum %9 == 0)
                res.pb(9);
        }
           

        forn(i,res.size())
        {
            cout << res[i] << ' ';
        }    
        cout << nl;
    }
    

    return 0;
}