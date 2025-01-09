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

const int M = 1e9 + 7;

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

    vector<int> n(t), k(t);

    // Leer los valores de n y k
    forn(i, t) {
        cin >> n[i];
    }
    int mxk = 0;
    forn(i, t) {
        cin >> k[i];
        mxk = max(mxk,k[i]);
    }

    ll p[mxk+1];
    p[0] = 1;
    for (int i = 1; i <= mxk; i++)
    {
        p[i] = (2*p[i-1])%M;
    }

    forn(i,t)
    {
        cout << p[k[i]] << nl;
    }

    return 0;
}