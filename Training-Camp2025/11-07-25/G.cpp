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
const double EPS = 1e-10;

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

    //for(int n = 31; n <= 31; n++){
    int n; cin >> n;
    int color = 1;
    int a[1000][1000]; memset(a,-1,sizeof(a));
    for (int l = 0; l < (n+21)/21; l++) {
        for (int k = 0; k < (n+7)/7; k++) {
            for (int i = 0; i < 21; i++) {
                for (int j = 0; j < 7; j++) {
                    if (i + 21 * l < n && j + 7 * k < n)
                        a[i + 21 * l][j + 7 * k] = color;
                }
            }
            color++;
        }
    }


    // int last_used = 0;
    // int used[11000] = {};
    forn(i,n)
    {
       forn(j,n)
       {
           int c = a[i][j];
           //  if(c==-1) cout<<"putaso mal\n";
           //  if(c==0) cout<<"medio puto"<<nl;
        //    if (10 + (n*n)/100 < c)
        //    {
        //         while (used[last_used] >= 150)
        //         {
        //             last_used++;
        //         }
        //         c = (last_used+1);
        //    }
        //    used[c-1]++;
           cout << c << " ";
       }
       cout << nl;
    }

    // const int R2 = 100; // radio al cuadrado
    // int count = 0;

    // Área de dibujo centrada en (14, 22), desde (i-15,j-15) hasta (i+15,j+15)
    // for (int i = 14 - 15; i <= 14 + 15; ++i) {
    //     for (int j = 22 - 15; j <= 22 + 15; ++j) {
    //         if (i < 0 || j < 0 || i >= n || j >= n) {
    //             cout << "  ";  // fuera de la matriz
    //             continue;
    //         }

    //         int di = i - 14;
    //         int dj = j - 22;

    //         if (di * di + dj * dj <= R2) {
    //             if (di == 0 && dj == 0) cout << "X ";
    //             else cout << "@ ";
    //             count++;
    //         } else {
    //             cout << ". ";
    //         }
    //     }
    //     cout << '\n';
    // }
    // cout << "Cantidad de celdas en el radio: " << count << nl;
    
    
    // bool valid = true;
    // unordered_map<int, int> color_count;
    // int C = 10 + (n * n) / 100;

    // forn(i,n) forn(j,n) {
    //     int color = a[i][j];
    //     color_count[color]++;
    //     if (color < 1 || color > C) {
    //         cerr << "Color inválido " << color << " en celda (" << i << "," << j << "), fuera del rango [1," << C << "]\n";
    //         valid = false;
    //     }
    // }

    // for (auto &[c, cnt] : color_count) {
    //     if (cnt > 150) {
    //         cerr << "Color " << c << " usado " << cnt << " veces\n";
    //         valid = false;
    //     }
    // }

    // Validar la cantidad de colores únicos en vecindario de cada celda
    // cout << "n = " << n << nl;
    // forn(i,n) forn(j,n) {
    //     set<int> neighborhood_colors;
    //     forr(di,-10,11) {
    //         forr(dj,-10,11) {
    //             int ni = i + di;
    //             int nj = j + dj;
    //             if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
    //             if (di*di + dj*dj <= 100)
    //                 neighborhood_colors.insert(a[ni][nj]);
    //         }
    //     }
    //     if (neighborhood_colors.size() > 8) {
    //         cerr << "Celda (" << i << "," << j << ") tiene " << neighborhood_colors.size() << " colores vecinos\n";
    //         valid = false;
    //     }
    // }

    // if (valid) cout << "VALIDO\n";
    // else cout << "INVALIDO\n";


    //}

    return 0;
}