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
        string t; cin >> t;
        string s;

        int res = 0;
        forn(i,t.size()) 
        {
            if(t[i] != '4') s+=t[i];
            else res++;
        }
        
        int n = s.size();
        int pref[n+1] = {};  forn(i,n) pref[i+1] = (pref[i] + ((s[i] != '2') ? 1 : 0));
        int suff[n+1] = {}; dforn(i,n) suff[i] = (suff[i+1] + ((s[i] == '2') ? 1 : 0));

        int mn = 1e9;
        forn(i,n+1)
        {
            mn = min(mn, pref[i] + suff[i]);
        }

        cout << res + mn << nl;
    }
    
    return 0;
}