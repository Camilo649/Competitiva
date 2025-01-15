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
 
int t;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;

    while (t--)
    {
        int n,m;
        cin >> n >> m;
        int x[n], y[n];
        int sumx=0, sumy=0;
        forn(i,n)
        {
            cin >> x[i] >> y[i];
            sumx += x[i];
            sumy += y[i];
        }
        pair<int,int> startpos = make_pair(x[0],y[0]);
        pair<int,int> endpos = make_pair(sumx+m-1,sumy+m-1);
        cout << (endpos.first - startpos.first + 1 + endpos.second - startpos.second + 1) * 2 << nl;
    }
    

    return 0;
}