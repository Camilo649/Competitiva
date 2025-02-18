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
        string s;
        cin >> n >> s;

        bool flag = true;
        int firstp = n;
        int lasts = -1;
        int counts = 0;
        forn(i,n)
        {
            if (s[i] == 'p')
            {
                firstp = min(firstp,i);
            }
            else if (s[i] == 's')
            {
                lasts = max(lasts,i);
                counts++;
            }
        }

        if (firstp != n && lasts != -1)
        {
            if (firstp < lasts || (firstp != n-1 && lasts != 0 && n >=4))
            {
                flag = false;
            }
        }
    
        if (flag)
        {
            cout << "YES" << nl;
        }
        else
        {
            cout << "NO" << nl;
        }
    }
    
    return 0;
}