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

int ask(const vector<int>& q) {
    cout << "? " << q.size() << " ";
    for (int idx : q) cout << idx << " ";
    cout << nl;
    cout.flush();
    
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

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
        int max_len = 2 * n + 1;

        // Obtener la posicion mas a la derecha (z)
        int l = 1, r = max_len, z = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<int> q;
            forr(i, 1, mid+1) q.push_back(i);

            int res = ask(q);
            int k = q.size();

            if ((k - res) % 2 != 0) {
                z = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // Obtener la posicion mas a la izquierda (x)
        l = 1; r = max_len;
        int x = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<int> q;
            forr(i, mid, max_len+1) q.push_back(i);

            int res = ask(q);
            int k = q.size();

            if ((k - res) % 2 != 0) {
                x = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // Obtener la posicion del medio (y)
        l = x + 1; r = z - 1;
        int y = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<int> q;
            forr(i, 1, mid+1) q.push_back(i);
            q.push_back(z);

            int res = ask(q);
            int k = q.size();

            if ((k - res) % 2 != 0) {
                y = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        cout << "! " << x << " " << y << " " << z << nl;
        cout.flush();
    }
    
    return 0;
}