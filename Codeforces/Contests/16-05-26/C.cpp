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
const ll INF = 8e18;

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
        string a; cin >> a;
        int n; cin >> n;
        int m = a.size();
        vector<int> d;
        forn(i,n) 
        {
            int aux;
            cin >> aux;
            d.pb(aux);
        }
        sort(d.begin(), d.end());
        set<int> s; forn(i,n) s.insert(d[i]);

        ll res = 8e18; // Inicializar con algo muy grande
        string prefix = "";
        ll num_a = stoll(a);

        auto dist = [](ll x, ll y) -> ll {
            return (x > y) ? (x - y) : (y - x);
        };

        for (int i = 0; i < m; i++) {
            int actual = a[i] - '0';

            // 1. Intentar poner uno menor a 'actual' y rellenar con el más grande
            int d_menor = -1;
            for(int x : d) if(x < actual) d_menor = max(d_menor, x);
            if(d_menor != -1) {
                string cand = prefix + to_string(d_menor);
                while(cand.size() < m) cand += to_string(d.back());
                res = min(res, dist(num_a, stoll(cand)));
            }
        
            // 2. Intentar poner uno mayor a 'actual' y rellenar con el más chico
            int d_mayor = 10;
            for(int x : d) if(x > actual) d_mayor = min(d_mayor, x);
            if(d_mayor != 10) {
                string cand = prefix + to_string(d_mayor);
                while(cand.size() < m) cand += to_string(d[0]);
                res = min(res, dist(num_a, stoll(cand)));
            }
        
            // 3. ¿Podemos seguir manteniendo el prefijo igual?
            if (s.count(actual)) {
                prefix += a[i];
                if (i == m - 1) res = 0; // El número exacto existe
            } else {
                break; // Ya no podemos copiar a[i], hay que romper acá o antes
            }
        }

        string res_min, res_max;
        forn(i,m-1)
        {
            res_min += to_string(d.back());
        }
        forn(i,m+1)
        {
            res_max += to_string(d[0] == 0 && i == 0 && n > 1 ? d[1] : d[0]);
        }

        ll num_min = res_min.empty() ? INF : stoll(res_min);
        ll num_max = (res_max.empty() || res_max.size() > 18) ? INF : stoll(res_max);
        ll num = stoll(a);
        cout << min(min(res, dist(num, num_min)), dist(num_max, num)) << nl;
    }
    return 0;
}