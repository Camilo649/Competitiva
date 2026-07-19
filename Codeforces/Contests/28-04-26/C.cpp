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

using namespace std;

// Función que verifica si es posible alcanzar un cierto MEX 'M'
bool check(int M, const vector<int>& v) {
    vector<int> gaps;
    vector<bool> exact(M, false);
    vector<int> available;

    // Clasificamos los números
    for (int x : v) {
        if (x < M && !exact[x]) {
            exact[x] = true; // Lo usamos tal cual es
        } else {
            available.push_back(x); // Sobra para usar de relleno
        }
    }

    // Identificamos los huecos que nos quedaron
    for (int i = 0; i < M; i++) {
        if (!exact[i]) gaps.push_back(i);
    }

    // Si hay más huecos que sobras, es imposible
    if (available.size() < gaps.size()) return false;

    int g_sz = gaps.size();
    int a_sz = available.size();
    
    // Emparejamos los huecos más grandes con las sobras más grandes
    for (int i = 0; i < g_sz; i++) {
        if (available[a_sz - g_sz + i] < 2 * gaps[i] + 1) {
            return false; 
        }
    }
    return true;
}

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
        vector<int> v(n); forn(i,n) cin >> v[i];

        // Ordenar es clave para que los huecos y sobras ya queden listos de menor a mayor
        sort(v.begin(), v.end());

        // Búsqueda binaria para encontrar el máximo MEX posible
        int L = 0, R = n, ans = 0;
        while(L <= R) {
            int mid = L + (R - L) / 2;
            if (check(mid, v)) {
                ans = mid;
                L = mid + 1; // Si pudimos, intentamos buscar uno más alto
            } else {
                R = mid - 1; // Si no pudimos, bajamos la vara
            }
        }

        int mexwf = ans;
        cout << mexwf << nl;
    }
    
    return 0;
}