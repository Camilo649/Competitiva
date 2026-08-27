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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;
const int INF = 1e6;

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
    
    int n; cin >> n;
    int a[n]; forn(i,n) cin >> a[i];
    int m; cin >> m;
    int b[m]; forn(i,m) cin >> b[i];

    sort(a, a+n);
    sort(b, b+m);

    int res = 0;
    forn(i,n)
    {
        forn(j,m)
        {
            if(abs(a[i]-b[j]) <= 1)
            {
               b[j] = INF;
               res++; 
               break;
            }
        }
    }

    cout << res << nl;
    
    return 0;
}