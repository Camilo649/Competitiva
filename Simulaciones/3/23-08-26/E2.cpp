#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

typedef long long ll;

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,P; cin >> n >> P;

    vector<tuple<ll,ll,ll>> w(n); // (A,B,C)
    forn(i,n)
    {
        ll a,b,c; cin >> a >> b >> c;
        w[i] = {a,b,c};
    }

    // Exchange argument: dadas dos armas 1 y 2 y un poder p cualquiera,
    // comparamos el poder resultante de aplicar 1-luego-2 vs 2-luego-1.
    // Ignorando el floor (aproximación continua), conviene aplicar primero
    // el arma "1" si  B1*(A2-1) >= B2*(A1-1).
    // Esto define un orden total fijo, óptimo para CUALQUIER subconjunto.
    sort(w.begin(), w.end(), [](const tuple<ll,ll,ll>& x, const tuple<ll,ll,ll>& y){
        ll A1=get<0>(x), B1=get<1>(x);
        ll A2=get<0>(y), B2=get<1>(y);
        return B1*(A2-1) > B2*(A1-1);
    });
    // Ahora w[0] es la que conviene aplicar primero, w[n-1] la última.

    vector<ll> dp(P+1, 0);
    // dp[pi] = maximo daño posible arrancando con pi puntos de poder,
    // usando (opcionalmente) un subconjunto de las armas ya "incorporadas".

    // Recorremos las armas en orden INVERSO al de aplicación: la razón es
    // que la transición dp[pi] = max(dp[pi], C + dp[pi2]) aplica el arma
    // actual PRIMERO (pi -> pi2) y deja lo ya incorporado para después.
    // Entonces lo que se procesa último en este loop es lo que se aplica
    // primero cronológicamente -> hay que arrancar por w[n-1] y terminar en w[0].
    dforn(i,n)
    {
        ll A = get<0>(w[i]), B = get<1>(w[i]), C = get<2>(w[i]);

        // pi descendente: asegura que dp[pi2] (pi2 < pi siempre) todavía
        // no fue tocado por ESTA arma en este mismo pase -> se usa como
        // máximo una vez (igual que el truco de knapsack 0/1 de toda la vida).
        dforr(pi,1,P+1)
        {
            ll num = pi - B;
            ll pi2 = num >= 0 ? num / A : -((-num + A - 1) / A);
            if(pi2 < 0) continue;
            dp[pi] = max(dp[pi], C + dp[pi2]);
        }
    }

    cout << dp[P] << '\n';

    return 0;
}