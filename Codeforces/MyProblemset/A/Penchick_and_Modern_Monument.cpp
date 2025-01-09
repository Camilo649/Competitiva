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
        int h[n];
        set<int> s;
        int count[n] = {};
        forn(i,n)
        {
            cin >> h[i];
            if (s.find(h[i]) != s.end())
            {
                s.insert(h[i]);
                count[h[i]-1] = 1;
            }
            else
            {
                count[h[i]-1]++;
            }
        }

        int mostcommon;
        int maxcount = 0;
        forn(i,n)
        {
            if (count[i] > maxcount)
            {
                mostcommon = i+1;
                maxcount = count[i];
            }
        }

        int result[n];
        result[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (h[i-1] < h[i])
            {
                result[i] = result[i-1];
            }
            else if (h[i-1] == h[i])
            {
                if (h[i] != mostcommon)
                {
                    result[i] = result[i-1] + 1;
                }
                else
                {
                    result[i] = result[i-1];
                }
            }
            else
            {
                result[i] = result[i-1] + 1;
            }
        }

        cout << result[n-1] << nl;
    }
    

    return 0;
}