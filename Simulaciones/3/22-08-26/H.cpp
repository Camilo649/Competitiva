#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i, 0, n)

#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e6 + 6;

using namespace std;

// HORIZONTAL -> 0
// VERTICAL   -> 1

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    int a[n][n];
    forn(i,n)
    {
        forn(j,n)
        {
            cin >> a[i][j];
            a[i][j]--;
        }
    } 
    
    pair<int,int> pos_org[n*n];
    forn(i,n)
    {
        forn(j,n)
        {
            pos_org[a[i][j]] = {i,j};
        }
    } 

    int best_row[n] = {}, best_col[n] = {};
    forn(val,n*n)
    {
        pair<int,int> p = pos_org[val];
        int i = p.fst, j = p.snd; 
        int br = best_row[i], bc = best_col[j];
        best_row[i] = max(br, bc+1);
        best_col[j] = max(br+1, bc);
    }

    int mx = 0;
    forn(k,n)
    {
        mx = max(mx, best_col[k]);
        mx = max(mx, best_row[k]);
    }

    cout << mx << nl;

    return 0;
}