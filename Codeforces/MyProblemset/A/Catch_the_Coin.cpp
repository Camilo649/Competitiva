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

const int MAXN = -1;

using namespace std;
 
int n;

int main()
{
    #ifdef CAM
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;

    int x, y;
    while (n--) {
        cin >> x >> y;

        if(y<-1) {
            if ((abs(x) == 2) && (y == -1))
            {
                cout << "YES" << nl;
            }
            else
            {
                cout << "NO" << nl;
            } 
        }
        else
        {
            cout << "YES" << nl;
        }    
    }

    return 0;
}