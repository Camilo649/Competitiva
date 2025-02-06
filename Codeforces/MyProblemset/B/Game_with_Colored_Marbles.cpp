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
        map<int,int> m;
        forn(i,n)
        {
            int c;
            cin >> c;
            if (m.count(c) == 0)
            {
                m[c] = 1;
            }  
            else
            {
                m[c]++;
            } 
        }

        int pcount = 0, icount = 0, onecount = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second%2==0)
            {
                pcount++;
            }
            else if (it->second == 1)
            {
                onecount++;
            }
            else
            {
                icount++;
            }
        }

        int Alices_points = icount + pcount;
        if (onecount != 0)
        {
            Alices_points += ((onecount+1)/2)*2;
        }  
        cout << Alices_points << nl;
    }
    
    return 0;
}