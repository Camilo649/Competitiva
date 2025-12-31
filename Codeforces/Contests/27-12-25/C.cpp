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
        int n; cin >> n;
        int a[n];
        forn (i,n) cin >> a[i];

        ll sum_abs[n+1];
        sum_abs[0] = 0;
        sum_abs[1] = a[0];
        ll sum_neg[n+1];
        sum_neg[0] = 0;
        forr(i,1,n) sum_abs[i+1] = sum_abs[i] + abs(a[i]);
        forn(i,n) sum_neg[i+1] = sum_neg[i] - a[i];
        ll X = -1e9 -6;

        forn(i,n){
            X = max(X, sum_abs[i] + (sum_neg[n]-sum_neg[i+1]));
        }

        cout << X << nl;
    }
    
    return 0;
}