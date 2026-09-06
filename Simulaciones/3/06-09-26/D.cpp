#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

string a[1000];

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    forn(i, n){
        string ai; cin>>ai;
        a[i] = ai;
        forr(j, m, 1000) a[i] += 'M';
    }
    forr(i, n, 1000) forr(j, 0, 1000) a[i] += 'M';
    


    int b[] = {1,1,1,1,1,1,1,1};

    forn(i, n) forn(j, m) if (a[i][j] != a[m-j-1][i    ]) b[1] = 0;
    forn(i, n) forn(j, m) if (a[i][j] != a[n-i-1][m-j-1]) b[2] = 0;
    forn(i, n) forn(j, m) if (a[i][j] != a[j    ][n-i-1]) b[3] = 0;

    forn(i, n) forn(j, m) if (a[i][j] != a[n-i-1][j    ]) b[4] = 0;
    forn(i, n) forn(j, m) if (a[i][j] != a[j    ][i    ]) b[5] = 0;
    forn(i, n) forn(j, m) if (a[i][j] != a[i    ][m-j-1]) b[6] = 0;
    forn(i, n) forn(j, m) if (a[i][j] != a[m-j-1][n-i-1]) b[7] = 0;

    cout << b[0] + b[1] + b[2] + b[3] + b[4] + b[5] + b[6] + b[7] << nl;


    return 0;
}