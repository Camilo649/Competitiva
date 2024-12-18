#include<bits/stdc++.h>
using namespace std;
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
//#define MAT
// redefiniciones
typedef long long ll;
typedef long double ld;
//typedef pair<int, int> ii;
const int MAXN = -1;                                              // Redefinir a gusto para el maximo del arreglo 
 
int n;
 
int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        cout << a*b << '\n';
    }
    
    
    return 0;
}