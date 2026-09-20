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

const int MAXN = -1;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v; cin >> v;
    int n; cin >> n;
    
    n = v*n;

    //cout << n << nl;

    forr(i, 1, 10){
        int m = (n * i) / 10;
        if ((m * 10) >= n * i){
            cout << m << nl;
        }
        else {
            cout << m + 1 << nl;
        }
    }

    return 0;
}