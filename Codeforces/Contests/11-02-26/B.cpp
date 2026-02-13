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

        int i = 0;
        bitset<MAXN> b;
        while (i<n)
        {
            b[i] = (p[max(i-1, 0)] == a[i]) || (p[i] == a[i]) || (p[min(i+1, n-1)] == a[i]);
            i++;
        }
        
        i = 0;
        while (i<n)
        {
            if(b[i] == 1)
            {
                int l = i-1;
                while (l>=0 && a[l] == a[i])
                {
                    b[l] = 1;
                    l--;
                }
                int r = i+1;
                while (r<n && a[i] == a[r])
                {
                    b[r] = 1;
                    r++;
                }
            }
            i++;
        }

        bool flag = true;
        forr(i,1,n) if(p[i-1] == a[i] && p[i] == a[i-1]) flag = false;

        if((int)b.count() == n && flag) cout << "YES";
        else cout << "NO";
        cout << nl;
    }
    
    return 0;
}