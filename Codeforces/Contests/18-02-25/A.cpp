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
        // int b[n-2];
        string s(n-2,'0');
        forn(i,n-2)
        {
            // cin >> b[i];
            int b;
            cin >> b;
            if (b==1)
            {
                s[i] = '1';
            }
            
        }

        int pos1 = s.find("101");

        // int a[n] = {};
        // bool flag = true;
        // int element = 1;
        // forr(i,1,n-1)
        // {
        //     if (b[i] == '1')
        //     {
        //         if (a[i-1] == 0 && a[i] == 0 && a[])
        //         {
        //             /* code */
        //         }
                

        //     }
        //     else
        //     {

        //     }
        // }

        if(pos1 != string::npos)
        {
            cout << "NO" << nl;
        }
        else
        {
            cout << "YES" << nl;
        }
    }
    
    return 0;
}