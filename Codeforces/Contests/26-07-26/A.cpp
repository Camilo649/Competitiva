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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        int w[n]; forn(i,n) cin >> w[i];

        int l = 0, r = 1e9+6;

        forn(i,n)
        {
            if(i%2==0 && w[i] < r) r = w[i];
            else if(i%2 == 1 && w[i] > l) l = w[i];
        }

        bool flag = false;
        set<int> s; forn(i,n) s.insert(w[i]);
        forr(k,l+1,r)
        {
            if(s.count(k) == 0)
            {
                flag = true;
                //cout << k << nl;
                break;
            }
        }

        if(flag && n%2 != 1)
        {
            cout << "YES";
        }
        else{
            cout << "NO";
        }

        cout << nl;
    }
    
    return 0;
}