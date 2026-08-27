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
        int n,k; cin >> n >> k;
        string res;

        if(k == 0)
        {
            int i = 0;
            while (i<n)
            {
                res += '0';
                i++;
                if(i<n) res += '1';
                i++;
            }

            cout << res;
        }
        else if(k == 1)
        {
            res += "011";
            int i = 3;
            while (i<n)
            {
                res += '0';
                i++;
                if(i<n) res += '1';
                i++;
            }

            if(n == 2) cout << -1;
            else cout << res;
        }
        else if(k == 2)
        {
            res += "0011";

            int i = 4;
            while (i<n)
            {
                res += '0';
                i++;
                if(i<n) res += '1';
                i++;
            }

            if(n-k <= 1) cout << -1;
            else cout << res;
        }
        else
        {
            int k0 = k/2 + 1;

            int i = 0;
            while (i<k0)
            {
                res += '0';
                i++;
            }
            while (i<k+2)
            {
                res += '1';
                i++;
            }
            while (i<n)
            {
                res += '0';
                i++;
                if(i<n) res += '1';
                i++;
            }

            if(n-k <= 1)
            {
                cout << -1;
            }
            else
            {
                cout << res;
            }
        }

        cout << nl;
    }
    
    return 0;
}