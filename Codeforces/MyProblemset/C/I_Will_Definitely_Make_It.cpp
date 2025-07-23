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
const double EPS = 1e-10;

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
        int n,k; cin >> n >> k;
        set<int> s;
        int height;
        forn(i,n)
        {
            int h;
            cin >> h;
            s.insert(h);
            if (i+1 == k)
            {
                height = h;
            }
        }

        int water_level = 0;
        bool flag = true;
        for (auto h : s)
        {
            if(h <= height)
                continue;
            int x = abs(height - h);
            flag = (height >= water_level + x);
            if (!flag)
                break;
            water_level += x;
            height = h;
        }

        if (flag)
        {
            cout << "YES" << nl;
        }
        else
        {
            cout << "NO" << nl;
        }
    }
    
    return 0;
}