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
//#define MAT
// redefiniciones
typedef long long ll;
typedef long double ld;
 
using u64 = uint64_t;
using namespace std;
const int MAXN = -1;
 
int n;
 
int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif
 
    cin >> n;
 
    int mz[n][n];
    memset(&mz, 0, sizeof(int)*n*n);
 
    for (int j = 0; j < n; j++)
    {
        mz[0][j] = 1;
    }
 
 
    forn(i,n){
        mz[i][0] = 1;
    }
 
    for(int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++)
        {
            mz[i][j] += (mz[i-1][j] + mz[i][j-1]);
        }
    }
 
    cout << mz[n-1][n-1] << nl;
 
    return 0;
}