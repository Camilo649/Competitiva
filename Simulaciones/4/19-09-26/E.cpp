#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (int) b-1; i>= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

const int MAXN = 3e3 + 5;
const ll INF   = 1e9;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << endl
#endif

ll a[MAXN][2];

ll solve(int i, int j, int n)
{
    ll res = a[i][1] + a[i][0]-1;
    res += 2*(a[j][0]);
    ll empty = 0;
    forn(k,n)
    {
        if(k==i || k==j) continue;
        if(a[k][1] == 0) empty++;
        res += min(a[k][0] + a[k][1], 2*a[k][0]);
    }

    ll summ = 0;
    forn(k,n)
    {
        summ += a[k][0];
    }

    return (empty > summ ? summ : res - empty);
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;

    forn(i,n)
    {
        cin >> a[i][0];
        cin >> a[i][1];
    }

    ll ans = INF;
    forn(i,n)
    {
        forn(j,n)
        {
            if(i==j) continue;
            ans = min(ans,solve(i,j,n));
        }
    }

    cout << ans << nl;

    return 0;
}