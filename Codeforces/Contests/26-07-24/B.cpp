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
#define CAM
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1001;

using namespace std;
 
int t;
string mz[MAXN];
int res[MAXN][MAXN];

int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;

    while (t--)
    {
        int n,k;
        cin >> n >> k;

        //cout << n << ' ' << k << nl;


        forn(i,n){
            cin >> mz[i];
        }

        int col,fil;
        fil = 0;
        forn(i,n/k){
            col = 0;
            forn(j,n/k) {
                res[i][j] = mz[fil][col] - '0';
                col += k;
            }
            fil += k;
        }

        forn(i,n/k){
            forn(j,n/k){
                cout << res[i][j];
            }
            cout << nl;
        }
        
    }
    

    return 0;
}