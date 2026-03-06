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
        int k; cin >> k;
        
        int dp[k+1] = {};
        forn(i,k)
        {
            if((dp[i] != 0 || i==0) && i+5 <= k) dp[i+5] = dp[i]+1;
        }

        dp[1] = 1;

        if(dp[k] > 0 || k%5 == 3 || k%5 == 1) 
        {
            cout << "YES" << nl;
            if(k==1)
            {
                cout << 1 << nl;
                cout << '*' << nl;
                cout << '.' << nl;
                continue;
            }

            string s;
            if(k%5 == 3 || k%5 == 1)
            {
                s += "*.";
            }
            int count;
            if(k%5 == 0) count = dp[k];
            else if(k%5 == 3) count = dp[k-3];
            else count = dp[k-6];
            while (count > 0)
            {
                s += ".*.";
                count--;
            }
            if(k%5 == 1)
            {
                s += ".*";
            }
            int n = s.size();
            string s2;
            forn(i,n) s2 += ".";
            cout << n << nl;
            cout << s << nl;
            cout << s2 << nl;
        }
        else
        {
            cout << "NO" << nl;
        }

    }
    
    return 0;
}