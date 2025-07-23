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
const double EPS = 1e-10;

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
        int n; cin >> n;
        string s; cin >> s;
        int a[n];
        forn(i,n)
        {
            cin >> a[i];
        }
        int bad_pos = 0;
        forn(i,n)
        {
            if(a[i] != (i+1))
            {
                bad_pos++;
            }
        }
        if (bad_pos > 3)
        {
            cout << "Bob" << nl;
        }
        else if (bad_pos == 0)
        {
            cout << "Alice" << nl;
        }
        else if (n == 2)
        {
            cout << "Alice" << nl;
        }
        else
        {
            if ((n == bad_pos && s == "Bob") || (bad_pos == 2 && s == "Alice"))
            {
                cout << "Alice" << nl;
            }
            else
            {
                cout << "Bob" << nl;
            }
        }
        
    }
    
    return 0;
}