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

const int MAXN = 1e9;

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

        set<int> posible;
        posible.insert(n);
        int i = n;
        int ops = 0;
        while (i > 1)
        {
            if(posible.count(k) == 1) break;
            posible.insert(i/2);
            posible.insert((int)ceil((double)i/2));
            i = (int)ceil((double)i/2)%2 == 1 ? (int)ceil((double)i/2) : i/2;
            ops++;
        }

        cout << (posible.count(k) == 1 ? ops : -1) << nl;
    }
    
    return 0;
}