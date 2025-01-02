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

const int MAXN = 8*1e5;

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
        int n;
        cin >> n;

        int l[n], r[n];
        multiset<int> ms;
        int a[2*n] = {};
        forn(i,n)
        {
            cin >> l[i] >> r[i];
            if (l[i]==r[i])
            {
                ms.insert(l[i]);
                a[l[i]-1] = 1;
            }
        }
        vector<int> v;
        v.push_back(0);
        for(int i = 0; i < 2*n; i++) {
            v.push_back(a[i] + v[i]);
        }

        int res[n];
        forn(i,n)
        {
            if (l[i]==r[i])
            {
                res[i] = ms.count(l[i]) < 2;
            }
            else
            {
                res[i] = (v[r[i]] - v[l[i]-1]) < (r[i] - l[i] + 1);
            }

            cout << res[i];
        }

        cout << nl;
    }
    

    return 0;
}