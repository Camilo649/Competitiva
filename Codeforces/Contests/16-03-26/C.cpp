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
        ll a,b,c,m; cin >> a >> b >> c >> m;

        ll A,B,C;
        A = (m/a)*6 - (m/lcm(a,b))*3 - (m/lcm(a,c))*3 + (m/lcm(a,lcm(b,c)))*2;
        B = (m/b)*6 - (m/lcm(b,a))*3 - (m/lcm(b,c))*3 + (m/lcm(b,lcm(a,c)))*2;
        C = (m/c)*6 - (m/lcm(c,a))*3 - (m/lcm(c,b))*3 + (m/lcm(c,lcm(a,b)))*2;

        cout << A << " " << B << " " << C << nl;
    }
    
    return 0;
}