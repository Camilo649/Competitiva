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

const int MAXN = 536870911;

using namespace std;
 
int t,n;

int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;
    while (t--)
    {
        cin >> n;
        int b[n-1];
        forn(i,n-1){
            cin >> b[i];
        }

        int res[n];
        res[0] = b[0];
        bool SePuede = true;
        for (int i = 1; i < n-1; ++i) {
            res[i] = (b[i-1] | b[i]) | b[i];
            if((res[i-1]&res[i]) != b[i-1]) {
                cout << -1;
                SePuede = false;
                break;
            }
        }
        res[n-1] = b[n-2];
        if(SePuede && ((res[n-2]&res[n-1]) != b[n-2])) {
                cout << -1;
                SePuede = false;
        }


        if (SePuede) {
            forn(i,n) {
                cout << res[i] << ' ';
            }
        }

        cout << nl;
    }

    return 0;
}