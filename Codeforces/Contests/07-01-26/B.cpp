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
        int k; cin >> k;
        int a[n]; forn(i,n) cin >> a[i];

        map<int,int> m;
        forn(i,n)
        {
            if(m.count(a[i]) == 0) m[a[i]] = 1;
            else m[a[i]]++;
        }

        int ops = n-k+1;
        for (auto [key, value] : m) {
            int dif = max(value-1, 0);
            ops -= dif;
        }

        while (ops > 0)
        {
            auto it = std::prev(m.end());
            m.erase(it);
            ops --;
        }

        int ans = 0;
        int key_ant = -1;
        for (auto [key, value] : m) {
            if(value > 0 && key == key_ant + 1){
                ans++;
                key_ant = key;
            }
            else break;
        }

        cout << ans << nl;
        
    }
    
    return 0;
}