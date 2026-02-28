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
        int a[n]; forn(i,n) cin >> a[i];

        vector<int> stack;

ll sum_prefix[n];
dforn(i,n) {
    while(!stack.empty() && stack.back() == a[i]+1)
        stack.pop_back();
    stack.push_back(a[i]);
    sum_prefix[i] = stack.size();
}
reverse(stack.begin(), stack.end()); // indices crecientes

ll ans = 0;

forn(i,n) {
    ans += sum_prefix[i];
}

        cout << ans << nl;
    }
    
    return 0;
}