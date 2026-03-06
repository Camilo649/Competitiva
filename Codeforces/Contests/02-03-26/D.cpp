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
        int n,m; cin >> n >> m;
        int a[n], b[m];
        forn(i,n) cin >> a[i];
        forn(i,m) cin >> b[i];

        set<int> sa, sb;
        if(n==1) sa.insert(a[0]);
        else
        {
            forr(i,1,n-1) sa.insert(a[i]);
        }
        if(m==1) sb.insert(b[0]);
        else
        {
            forr(i,1,m-1) sb.insert(b[i]);
        }

        bool flag = false;
        for (auto it = sa.begin(); it != sa.end(); it++) {
            if(sb.count(*it) == 1)
            {
                flag = true; break;
            }
        }

        cout << (flag ? "YES" : "NO") << nl;
    }
    
    return 0;
}