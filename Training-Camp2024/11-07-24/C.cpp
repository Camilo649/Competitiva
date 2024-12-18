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
const int MAXN = 1000*1000;                                              // Redefinir a gusto para el maximo del arreglo 
ll v[MAXN];
int n;
 
int main()
{
#ifdef MAT
    freopen("input.in", "r", stdin);
#endif
    v[0] = 1;
    for (int i = 1; i < 1000*1000; i++){
        v[i] = (v[i-1] * 2)% 998244353;
//        cout << v[i] <<' ';
    }
    ll x, y;
    cin >> x >> y;
    ll pro = 4*v[x+y-2]%(ll)998244353;
    cout << pro << nl;
    
    return 0;
}
