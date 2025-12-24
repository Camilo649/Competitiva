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

void solve (int n)
{
    ll res = 0;
    if (n == 1) cout << 0;
    else if (n == 2) cout << 6;
    else if(n == 3) cout << 28;
    else if (n == 4) cout << 96;
    else
    {
        ll nn = n*n; nn--;
        res += (nn-8) * (n-4)*(n-4);
        res += 4*(nn-4);
        res += ((n-2)*(n-2) - (n-4)*(n-4) - 4) * (nn-6);
        res += 4*(nn-2);
        res += 8*(nn-3);
        res += (n*n - (n-2)*(n-2) - 12) * (nn-4);
        cout << res/2;
    }
    cout << nl;
}

int main()
{
    // #ifdef MILF
    //     freopen("../input.txt", "r", stdin);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int k; cin >> k;
    forr(i,1,k+1) solve(i);
    
    return 0;
}