#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

int n;

bool solve(vector<int>& a) {
    int pk = find(a.begin(), a.end(), n) - a.begin();

    // los fijos tienen que subir hasta N y bajar despues
    int prev = 0;
    for (int i = 0; i < pk; i++) if (a[i]) {
        if (a[i] <= prev) return false;
        prev = a[i];
    }
    prev = n + 1; // INF
    for (int i = pk + 1; i < n; i++) if (a[i]) {
        if (a[i] >= prev) return false;
        prev = a[i];
    }

    // valores libres
    vector<bool> used(n + 2, false);
    for (int x : a) used[x] = true;
    set<int> s;
    for (int v = 1; v <= n; v++) if (!used[v]) s.insert(v);

    // bloques de ceros: (hi, lo, i, j)
    vector<array<int,4>> blocks;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) continue;
        int j = i;
        while (j + 1 < n && a[j + 1] == 0) j++;
        int lo, hi;
        if (j < pk) {               // subida
            lo = (i > 0 ? a[i - 1] : 0) + 1;
            hi = a[j + 1] - 1;
        } else {                    // bajada
            hi = a[i - 1] - 1;
            lo = (j + 1 < n ? a[j + 1] : 0) + 1;
        }
        blocks.push_back({hi, lo, i, j});
        i = j;
    }

    sort(blocks.begin(), blocks.end());

    for (auto& [hi, lo, i, j] : blocks) {
        int k = j - i + 1;
        vector<int> vals;
        while (k--) {
            auto it = s.lower_bound(lo);
            if (it == s.end() || *it > hi) return false;
            vals.push_back(*it);
            s.erase(it);
        }
        sort(vals.begin(), vals.end());
        if (j > pk) reverse(vals.begin(), vals.end());
        for (int t = 0; t < (int)vals.size(); t++) a[i + t] = vals[t];
    }
    return true;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    auto out = [&](vector<int>& b) {
        for (int x : b) cout << x << " ";
        cout << '\n';
    };

    if (find(a.begin(), a.end(), n) != a.end()) {
        if (solve(a)) out(a); else cout << "*\n";
        return 0;
    }

    int p = max_element(a.begin(), a.end()) - a.begin();
    if (a[p] == 0) {                // no hay ningun fijo
        a[0] = n;
        solve(a);
        out(a);
        return 0;
    }

    vector<int> cand;
    if (p > 0 && a[p - 1] == 0) cand.push_back(p - 1);
    if (p + 1 < n && a[p + 1] == 0) cand.push_back(p + 1);

    for (int pos : cand) {
        vector<int> b = a;
        b[pos] = n;
        if (solve(b)) { out(b); return 0; }
    }
    cout << "*\n";

    return 0;
}