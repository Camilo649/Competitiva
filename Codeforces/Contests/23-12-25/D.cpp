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
        vector<int> res;
        unordered_set<int> added;

        res.pb((1<<n)-1);
        dforn(i,n)
        {
            int val = (1<<i)-1;
            res.pb(val);
            added.insert(val);
            int j = 1;
            while (val + j*(1<<i) < (1<<n)-1)
            {
                if (added.count(val + j*(1<<i)) == 0)
                {
                    res.pb(val + j*(1<<i));
                    added.insert(val + j*(1<<i));
                }
                j++;
            }
        }

        forn(i,res.size())
        {
            added.insert(res[i]);
        }

        forn(i,1<<n)
        {
            if(added.count(i) == 0)
            {
                res.pb(i);
            }
        }

        forn(i,res.size()) 
        {
            cout << res[i] << " ";
        }
        cout << nl;
    }
    
    return 0;
}