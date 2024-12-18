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
 
int t,n,m,k;

int main()
{
    #ifdef CAM
        freopen("input.txt", "r", stdin);
    #endif

    cin >> t;

    while (t--)
    {
        cin >> n >> m >> k;

        // Colocar primero los números mayores o iguales a k
        for (int i = n; i >= k; --i) {
            cout << i << ' ';
        }
        // Luego, los números que están entre m+1 y k-1
        for (int i = k-1; i > m; --i) {
            cout << i << ' ';
        }
        // Finalmente, los números menores o iguales a m
        for (int i = 1; i <= m; ++i) {
            cout << i << ' ';
        }
        cout << nl;
    }
    
    



    return 0;
}