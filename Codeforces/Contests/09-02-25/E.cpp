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
        int n,m,k;
        cin >> n >> m >> k;

        if (abs(n-m) > k || max(n,m) < k)
        {
            cout << -1 << nl;
            continue;
        }

        string s(n+m, 'c');
        if (n>=m)
        {
            int count = 0;
            while (count < k)
            {
                s[count] = '0';
                count++;
            }
            n-=k;

            while (n != 0 && m != 0)
            {
                s[k] = '1';
                s[k+1] = '0';
                n--;
                m--;
                k+=2;
            }
            
            while (n>m)
            {
                s[k] = '0';
                n--;
                k++;
            }
            while (m>n)
            {
                s[k] = '1';
                m--;
                k++;
            }
        }
        else
        {
            int count = 0;
            while (count < k)
            {
                s[count] = '1';
                count++;
            }
            m-=k;   

            while (n != 0 && m != 0)
            {
                s[k] = '0';
                s[k+1] = '1';
                n--;
                m--;
                k+=2;
            }
            
            while (n>m)
            {
                s[k] = '0';
                n--;
                k++;
            }
            while (m>n)
            {
                s[k] = '1';
                m--;
                k++;
            }
        }

        cout << s << nl;
    }
    
    return 0;
}