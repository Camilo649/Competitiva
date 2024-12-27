#include<bits/stdc++.h>

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

const int MAXN = 1e6 + 10;

using namespace std;
 
int t;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int sum = 0, count2 = 0, count3 = 0;
        forn(i,s.size())
        {
            sum += s[i] - '0';
            if (s[i] == '2')
            {
                count2++;
            }
            else if (s[i] == '3')
            {
                count3++;
            }
        }

        if (sum%9 == 0)
        {
            cout << "YES" << nl;
        }
        else
        {
            int m = 2*count2 + 6*count3;
            bitset<MAXN> dp;
            dp[0] = 1;
            int i = 0;
            for(i; i<=m; i++)
            {
                if (dp[i] == 1)
                {
                    if ((sum+i)%9 == 0)
                    {
                        int iaux = i;
                        int p = iaux/6;
                        iaux -= 6*min(p,count3);
                        p = iaux/2;
                        iaux -= 2*min(p,count2);
                        if (iaux == 0)
                        {
                            cout << "YES" << nl;
                            break;
                        }
                    }
                    dp[i+2] = 1;
                    dp[i+6] = 1;
                }
            }
            if (i == m+1)
                cout << "NO" << nl;
        }
    }

    return 0;
}