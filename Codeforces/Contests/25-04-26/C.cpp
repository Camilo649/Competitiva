#include <bits/stdc++.h>

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
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        int a[n]; forn(i,n) cin >> a[i];

        int aux[n]; forn(i,n) aux[i] = a[i];
        sort(a, a+n);
        int m = a[n/2];

        int b[n];
        forn(i,n)
        {
            if(aux[i] >= m) b[i] = 1;
            else b[i] = -1;
        }
        int sum[n+1]; sum[0] = 0;
        forn(i,n) sum[i+1] = sum[i] + b[i];

        int c[n];
        forn(i,n)
        {
            if(aux[i] > m) c[i] = 1;
            else c[i] = -1;
        }
        int sum2[n+1]; sum2[0] = 0;
        forn(i,n) sum2[i+1] = sum2[i] + c[i];

        // dp[i] = máximo número de subarreglos válidos en el prefijo de longitud i
        vector<int> dp(n + 1, -1);
        dp[0] = 0; // Caso base: prefijo de longitud 0 tiene 0 particiones

        for (int i = 1; i <= n; i++) {
            // Buscamos un punto de corte 'j' anterior a 'i'.
            // Como el subarreglo [j+1...i] debe ser de longitud impar,
            // 'i' y 'j' deben tener diferente paridad.
            int start_j = (i % 2 == 1) ? 0 : 1;
            
            for (int j = start_j; j < i; j += 2) {
                if (dp[j] != -1) { // Si el prefijo hasta j es válido
                    // Comprobamos si el segmento de (j a i] cumple la condición de la mediana
                    if (sum[i] - sum[j] > 0 && sum2[i] - sum2[j] <= 0) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        // dp[n] siempre será al menos 1 porque el arreglo completo es válido
        cout << dp[n] << nl;
    }
    
    return 0;
}