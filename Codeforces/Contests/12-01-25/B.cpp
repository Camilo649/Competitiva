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
        int n;
        cin >> n;
        int a[n], b[n];
        forn(i,n)
        {
            cin >> a[i];
        }
        forn(i,n)
        {
            cin >> b[i];
        }

        int mxf = 1e9, mns = 1e9;
        forn(i,n)
        {
            mxf = min(mxf, a[i]-b[i]);
            if ((a[i]-b[i]) >= 0)
            {
                mns = min(mns, a[i]-b[i]);
            } 
        }
        int count = 0;
        forn(i,n)
        {
            if (a[i]-b[i] < 0)
            {
                count++;
            }
        }

        mns = mns - abs(mxf);
        if (count > 1 || mns < 0 || mns == 1e9)
        {
            cout << "NO" << nl;
        }
        else
        {
            cout << "YES" << nl;
        }  
    }
    

    return 0;
}