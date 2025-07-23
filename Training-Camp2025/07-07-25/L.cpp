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
#define nl endl;
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
        //unordered_set <int> s;
        int a,b,c; a=1; b=2; c=3;
        cout << "?" << " " << a << " " << b << " " << c << nl;
        int res; cin >> res;
        
        while (res > 0 )
        {
            if (rand()%3 == 0)
            {
                a = res;
            }
            else if (rand()%3 == 1)
            {
                b = res;
            }
            else
            {
                c = res;
            }
            cout << "?" << " " << a << " " << b << " " << c << nl;
            cin >> res;
        }

        cout << "!" << " " << a << " " << b << " " << c << nl;
    }
    
    return 0;
}