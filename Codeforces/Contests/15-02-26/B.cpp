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
        int a[n+1]; forn(i,n) cin >> a[i+1];

        bool flag = true;
        map<int,vector<int>> m;
        forr(i,1,n+1)
        {
            int j = i;
            while (j < n+1)
            {
                m[i].pb(a[j]);
                j *= 2;
            }
            i++;
        }

        for (auto [key, value] : m) {
            sort(value.begin(), value.end());
            int aux = key;
            int i = 0;
            while (i<(int)value.size() && flag)
            {
                flag = value[i] == aux;
                aux *= 2;
                i++;
            }
            if(flag == false) break;
        }
        
        if(flag) cout << "YES";
        else cout << "NO";
        
        cout << nl;
    }
    
    return 0;
}