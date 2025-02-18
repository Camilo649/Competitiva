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
        int n;
        cin >> n;
        int a[n+1];
        unordered_map<int,int> m;
        forn(i,n)
        {
            cin >> a[i];
            if(m.count(a[i]) == 0) m[a[i]] = 1;
            else m[a[i]]++;
        }
        a[n] = a[n-1];

        int i = 0;
        int maxLength = 0;
        int l = 1,r = 1;
        if (n==1)
        {
            l = 1; r = 1; maxLength = 1;
        }
        else
        {
            while (i<n)
            {
                int length = 0;
                int maxL = i+1; 
                bool flag = false;
                while (i<n && m[a[i]] == 1)
                {
                    flag = true;
                    length++;
                    i++;
                }
                if (length > maxLength)
                {
                    l = maxL;
                    r = i;
                    maxLength = length;
                }
                if (!flag) i++;
            }
        }

        if (maxLength == 0)
        {
            cout << 0 << nl;
        }
        else
        {
            cout << l << ' ' << r << nl;
        }
        
    }
    
    return 0;
}