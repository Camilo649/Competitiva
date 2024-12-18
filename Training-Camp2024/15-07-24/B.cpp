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
#define MAT
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    string cmesa;
    cin >> cmesa;
    string c1,c2,c3,c4,c5;
    cin >> c1 >> c2 >> c3 >> c4 >> c5;

    if ((c1[0] == cmesa[0]) || (c2[0] == cmesa[0]) || (c3[0] == cmesa[0]) || (c4[0] == cmesa[0]) || (c5[0] == cmesa[0]))
    {
        //cout << cmesa << c1 << c2 << c3 << c4 << c5 << nl;
        cout << "YES" << nl;
    }
    else if ((c1[1] == cmesa[1]) || (c2[1] == cmesa[1]) || (c3[1] == cmesa[1]) || (c4[1] == cmesa[1]) || (c5[1] == cmesa[1]))
    {
        //cout << cmesa << c1 << c2 << c3 << c4 << c5 << nl;
        cout << "YES" << nl;
    }
    else
    {
        cout << "NO" << nl;
    }
    return 0;
}