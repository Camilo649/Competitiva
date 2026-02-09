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

const int MAXN = 2e5 + 6;

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
        int n; cin >> n;
        vector<int> a(n); forn(i,n) cin >> a[i];

        vector<int> ord(n);
        forn(i,n) ord[i] = a[i];
        sort(ord.begin(), ord.end());

        if(a == ord)
        {
            cout << -1 << nl;
            continue;
        }

        bitset<MAXN> b;
        forn(i,n) b[i] = a[i] != ord[i];

        int mx = ord[n-1];
        int mn = ord[0];
        int k = 1e9;
        forn(i,n)
        {
            if(b[i] == 1)
            {
                k = min(max(abs(a[i]-mx), abs(a[i]-mn)),k);
            }
        }

        cout << k << nl;
    }
    
    return 0;
}