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
        int a[n], b[n], c[n];
        forn(i,n) cin >> a[i];
        forn(i,n) cin >> b[i];
        forn(i,n) cin >> c[i];

        ll count_i = 0;
        ll count_k = 0;
        forn(l,n)
        {
            bool flag = true;
            int m = 0;
            while (m<n && flag)
            {
                if(b[m] <= a[(l+m)%n])
                {
                    flag = false;
                }
                m++;
            }
            if(flag) count_i++;

            flag = true;
            m = 0;
            while (m<n && flag)
            {
                if(c[(l+m)%n] <= b[m])
                {
                    flag = false;
                }
                m++;
            }
            if(flag) count_k++;
        }

        cout << count_i*count_k*n << nl;
    }
    
    return 0;
}