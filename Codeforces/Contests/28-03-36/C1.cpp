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
        int n,k; cin >> n >> k;
        int a[n], b[n];
        forn(i,n) cin >> a[i];
        forn(i,n) cin >> b[i];

        bool flag = true;

        // Posiciones 0..n-k-1 son FORZADAS: b[i] debe ser a[i]
        forn(i, min(n-k, k)) {
            if(b[i] == -1) b[i] = a[i];
            else if(b[i] != a[i]) { flag = false; break; }
        }

        // Posiciones n-k..k-1 son LIBRES: llenamos con diff
        if(flag) {
            unordered_map<int,int> diff;
            forn(i, k) diff[a[i]]++;
            forn(i, k) {
                if(b[i] != -1) {
                    diff[b[i]]--;
                    if(diff[b[i]] < 0) { flag = false; break; }
                    if(diff[b[i]] == 0) diff.erase(b[i]);
                }
            }
            if(flag) {
                vector<int> faltantes;
                for(auto& [val, cnt] : diff)
                    forn(j, cnt) faltantes.push_back(val);
                int fi = 0;
                forn(i, k)
                    if(b[i] == -1) b[i] = faltantes[fi++];
            }
        }

        // Deslizamos la ventana
        int r = k;
        while(flag && r < n)
        {
            if(b[r] == -1) b[r] = a[r];
            else if(a[r] != b[r]) flag = false;

            if(a[r-k] != b[r-k]) flag = false;

            r++;
        }

        cout << (flag ? "YES" : "NO") << nl;
    }
    
    return 0;
}