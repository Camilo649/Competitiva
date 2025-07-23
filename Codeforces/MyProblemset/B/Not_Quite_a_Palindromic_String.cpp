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

const int MAXN = 1e5 * 2 + 6;

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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        bitset<MAXN> bs(s);
        int c1 = bs.count();
        int c0 = (n - c1);
        int mn = max(c0, c1) - n / 2;
        int mx = c0/2 + c1/2;
        if(k >= mn && (k - mn) % 2 == 0 && k <= mx) cout << "YES";
        else cout << "NO";  
        cout << nl;
    }
    
    return 0;
}