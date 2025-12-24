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
        int n,s; cin >> n >> s;
        int a[n]; 
        multiset<int> ms;
        int sum = 0;
        forn(i,n)
        {  
            cin >> a[i];
            ms.insert(a[i]);
            sum += a[i];
        }

        
        if(s < sum)
        {
            forn(i,ms.count(0)) cout << 0 << ' ';
            forn(i,ms.count(1)) cout << 1 << ' ';
            forn(i,ms.count(2)) cout << 2 << ' ';
            cout << nl;
        }
        else if((s-sum)%2 == 0)
        {
            cout << -1 << nl;
        }
        else
        {
            if (s >= sum+3)
            {
                cout << -1 << nl;   
            }
            else
            {
                forn(i,ms.count(1)) cout << 1 << ' ';
                forn(i,ms.count(2)) cout << 2 << ' ';
                forn(i,ms.count(0)) cout << 0 << ' ';
                cout << nl;
            }
        }
    }
    
    return 0;
}