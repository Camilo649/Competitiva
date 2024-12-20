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
 
int t, n, m;

int main()
{
    // #ifdef MILF
    //     freopen("../input.txt", "r", stdin);
    // #endif

    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        string s;
        int x = 0;

        forn(i,n)
        {
            cin >> s;
            if ((m - (int) s.size()) >= 0) 
            {
                m -= s.size();
                x++;
            }
            else
            {
                m = 0;
            }
        }

        cout << x << nl;
    }

    return 0;
}