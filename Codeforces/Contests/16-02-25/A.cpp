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
        int res = 0;
        int i = 0;

        while (i<n && s[i] == '0')
        {
            i++;
        }

        while (i<s.size())
        {
            if(i<n && s[i] == '1') res++;
            while (s[i] == '1' && i<n)
            {
                i++;
            }

            if(i< n && s[i] == '0') res++;
            while (s[i] == '0' && i<n)
            {
                i++;
            }
        }

        cout << res << nl;
        
    }
    
    return 0;
}