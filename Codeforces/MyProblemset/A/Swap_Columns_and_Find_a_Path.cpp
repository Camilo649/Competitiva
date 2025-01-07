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
    
    cin>>t;

    while (t--)
    {
        int n;
        cin >> n;
        int f1[n], f2[n];
        forn(i,n)
        {
            cin >> f1[i];
        }
        forn(i,n)
        {
            cin >> f2[i];
        }

        int maxmin = -1e9, maxsum = -1e9;
        int mxpos;
        forn(i,n)
        {
            if(min(f1[i],f2[i]) > maxmin || min(f1[i],f2[i]) == maxmin && (f1[i] + f2[i]) > maxsum)
            {
                maxmin = min(f1[i],f2[i]);
                maxsum = f1[i] + f2[i];
                mxpos = i;
            }
        }

        int res = 0;
        forn(i,n)
        {
            if (i != mxpos)
                res += max(f1[i], f2[i]);
            else
                res += (f1[i] + f2[i]);
        }

        cout << res << nl;
    }
    

    return 0;
}