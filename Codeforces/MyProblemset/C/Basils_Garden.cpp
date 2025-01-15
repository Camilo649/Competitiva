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
        int n;
        cin >> n;
        ll h[n];
        forn(i,n)
        {
            cin >> h[i];
        }

        ll seconds[n];
        seconds[n-1] = h[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            if (h[i] > h[i+1])
            {
                if (h[i] > seconds[i+1])
                {
                    seconds[i] = h[i];
                }
                else
                {
                    seconds[i] = seconds[i+1] + 1;
                }
            }            
            else
            {
                seconds[i] = seconds[i+1] + 1;
            }
        }

        cout << seconds[0] << nl;
        
    }
    

    return 0;
}