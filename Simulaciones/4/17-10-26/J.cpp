#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef double ld;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ld ang; cin >> ang;
    int n; cin >> n;
    ang = (ang / 180) * acosl(-1);

    vector<pair<ld, int>> points;


    ld sang = sinl(ang);
    ld cang = cosl(ang);

    forn(i, n){
        int x0; cin >> x0;
        int h; cin >> h;
        ld H = h / sang;
        ld x1 = x0 + H * cang;
        points.pb({x0, 1});
        points.pb({x1, -1});
    }

    sort(ALL(points));

    int c = 0;
    ld last = 0;
    ld ans = 0;
    forn(i, 2*n){
        if (c > 0){
            ans += points[i].fst - last;
        }
        last = points[i].fst;
        c += points[i].snd;
    }

    cout << fixed << setprecision(8) << ans << nl;


    return 0;
}