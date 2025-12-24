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
#define nl '\n'
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
        int n,x; cin >> n >> x;
        x--;
        string s; cin >> s;

        int left_cost = x+1;
        int right_cost = n-x;
        
        int L = x-1;
        while (L >= 0 && s[L] == '.')
        {
            L--;
        }
        int R = x+1;
        while (R < n && s[R] == '.')
        {
            R++;
        }
        
        x++; R++; L++;
        cout << max(min(x, n - R + 2), min(L + 1, n - x + 1)) << nl;
    }
    
    return 0;
}