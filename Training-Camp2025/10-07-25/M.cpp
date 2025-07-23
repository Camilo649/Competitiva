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
int a,b,m,r0;

int next()
{
    r0 = (a*r0 + b)%m;
    return r0;
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> a >> b >> m >> r0;

    unordered_set<int> s;
    int a[m] = {};
    s.insert(r0);
    int t = 0;
    forn(i,m)
    {
        t++;
        int r = next();
        if (s.count(r) != 0)
        {
            t -= a[r];
            break;
        }
        s.insert(r);
        a[r] = t;
    }
    cout << t << nl;
    
    return 0;
}