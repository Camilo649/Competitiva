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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n,m; cin >> n >> m;
        int a[n]; forn(i,n) cin >> a[i];
        int b[m]; forn(i,m) cin >> b[i];

        bool flag = true;
        if(n <= m)
        {
            flag = false;
        }
        else
        {
            sort(a, a+n);
            sort(b, b+m);

            int l = 0, r = n/2, j = 0;
            while (l<n/2 && r<n && j<m)
            {
                if(a[l] <= b[j] && b[j] <= a[r]) 
                {
                    j++; l++; r++;
                }
                else if(a[l] <= b[j] && b[j] > a[r])
                {
                    r++;
                }
                else if(a[l] > b[j])
                {
                    flag = false;
                    break;
                } 
            }

            if(j!=m) flag = false;
        }

        if(flag)
        {
            cout << "YES" << nl;
        }
        else
        {
            cout << "NO" << nl;
        }
    }
    
    return 0;
} 