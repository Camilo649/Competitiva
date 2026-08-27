#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)

#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define pb push_back
#define fsr first
#define snd suseconds_t
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

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

    int h; cin >> h;
    if(h == 0) cout << 1;
    else if(h == 1) cout << 0;
    else if (h%2 == 0)
    {
        string res;
        forn(i, h/2)
        {
            res += '8';
        }
        cout << res;
    }
    else
    {
        string res = "4";
        h--;
        forn(i, h/2)
        {
            res += '8';
        }
        cout << res;
    }

    cout << nl;
    
    return 0;
}