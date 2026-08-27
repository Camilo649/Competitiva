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
#define GE
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
vector<int> Div;
void getDiv(int n) {
    Div.clear();
    for (int d = 1; d * d <= n; d++) {
        if (n%d == 0) {
            Div.push_back(d);
            Div.push_back(n/d);
        }
        if (d*d == n) Div.pop_back();
    }
    sort(Div.begin(), Div.end());
}

int main()
{
    #ifdef GE
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int a[n]; forn(i,n) cin >> a[i];

    sort(a, a+n);

    ll sum = 0;
    forn(i,n) sum += a[i];

    vector<int> diff;

    forr(i,1,n)
    {
        getDiv(a[i]);
        forn(j, Div.size())
        {
            int p = Div[j];
            diff.pb((a[0] + a[i]) - (a[0]*p + a[i]/p));
        }
    }

    sort(diff.rbegin(), diff.rend());

    cout << sum - max(diff[0], 0) << nl;

    return 0;
}