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
const int MAXN = -1; 
using namespace std;                                             // Redefinir a gusto para el maximo del arreglo 
 
int n;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> n;

    while (n--)
    {
        int a, b , c;
        cin >> a >> b >> c;
        
        int max = 0;

        int i, j, k;
        i = 0;
        for(; i <= 5; i++) {
            j = 0;
            for (; j <= 5; j++) {
                k = 0;
                for(; k <= 5; k++) {
                    if (((i + k + j) == 5) && (max < ((a+i)*(b+j)*(c+k))))
                    {
                        max = ((a+i)*(b+j)*(c+k));
                    }
                }
            }
        }
        cout << max << nl;
    }

    return 0;
}