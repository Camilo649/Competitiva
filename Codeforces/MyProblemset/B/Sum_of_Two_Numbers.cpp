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

int sum_digits (string s)
{
    int sum = 0;
    forn(i,s.size())
    {
        sum += s[i] - '0';
    }
    return sum;
}

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

        string s = to_string(n);
        int x = 0, y = 0;
        int D = s.size();
        bool flag = true;
        forn(i,D)
        {
            if(s[i] == '0') continue;
            int digit = 1 * (s[i] - '0');
            int val1 = digit/2;
            int val2 = (digit+1)/2;
            forn(j,D-i-1)
            {
                val1 *= 10;
                val2 *= 10;
            }
            if (flag)
            {
                x += val1;
                y += val2;
                if(digit%2 == 1) flag = false;
            }
            else
            {
                x += val2;
                y += val1;
                if(digit%2 == 1) flag = true;
            }
        }
        
        // string s1 = to_string(x);
        // string s2 = to_string(y);
        // int sum1 = sum_digits(s1);
        // int sum2 = sum_digits(s2);
        // int diff = abs(sum1-sum2);
        // if(diff > 1)
        // {
        //     int mx = -1;
        //     int index= -1;
        //     if(sum1 < sum2)
        //     {
        //         forn(i,D)
        //         {
        //             if(mx < s2[i] - '0')
        //             {
        //                 mx= s2[i] - '0';
        //                 index = i;
        //             }
        //         }
        //     }
        //     else
        //     {
        //         forn(i,D)
        //         {
        //             if(mx< s1[i] - '0')
        //             {
        //                 mx = s1[i] - '0';
        //                 index = i;
        //             }
        //         }
        //     }

        //     int val1 = 1 * diff/2;
        //     forn(j,D-index-1)
        //     {
        //         val1 *= 10;
        //     }
        //     if(sum1 < sum2)
        //     {
        //         x += val1;
        //         y -= val1;
        //     }
        //     else
        //     {
        //         x -= val1;
        //         y += val1;
        //     }
            
        // }

        cout << x << " " << y << nl;
    }
    
    return 0;
}