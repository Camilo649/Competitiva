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

const int MAXN = 2e5 + 6;

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
        int p[n];
        forn(i,n) cin >> p[i];
        int a[n]; forn(i,n) cin >> a[i];

        map<int,int> mn, mx, count, pos;
        forn(i,n)
        {
            mn[a[i]] = mn.count(a[i]) == 0 ? i : min(mn[a[i]], i);
            mx[a[i]] = mx.count(a[i]) == 0 ? i : max(mx[a[i]], i);
            count.count(a[i]) == 0 ? count[a[i]] = 1 : count[a[i]]++;
            pos[p[i]] = i;
        }

        bool flag = true;
        int i = 0;
        int lastPos = -1;
            
        while (i < n && flag)
        {
            int val = a[i];
        
            // 1️⃣ verificar bloque contiguo
            if ((mx[val] - mn[val]) != count[val] - 1)
            {
                flag = false;
                break;
            }
        
            // 2️⃣ verificar orden respecto al bloque anterior
            if (lastPos != -1 && pos[val] <= lastPos)
            {
                flag = false;
                break;
            }
        
            lastPos = pos[val];
        
            // saltar al siguiente bloque
            i = mx[val] + 1;
        }
        
        if(flag) cout << "YES";
        else cout << "NO";
        cout << nl;
    }
    
    return 0;
}