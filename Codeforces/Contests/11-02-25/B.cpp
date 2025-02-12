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
        multiset<int> ms;
        int mx = 0, mn = 1001;
        forn(i,n)
        {
            int a;
            cin >> a;
            mx = max(mx,a);
            mn = min(mn,a);
            ms.insert(a);
        }

        bool flag = true;
        forr(i,mn,mx)
        {
            if (ms.count(i) == 1)
            {
                flag = false;
                break;
            }

            while(ms.count(i) > 2)
            {
                ms.insert(i+1);
                auto it = ms.find(i);
                ms.erase(it);
            }
        }

        if (!(ms.count(mx)%2==0))
        {
            flag = false;
        }

        if (flag)
        {
            cout << "Yes" << nl;
        }
        else
        {
            cout << "No" << nl;
        }
        
        
    }
    
    return 0;
}