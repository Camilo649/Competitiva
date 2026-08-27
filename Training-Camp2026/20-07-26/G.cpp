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
 
int tests;

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

    map<int,int> pos;
    forn(i,n)
    {
        pos[a[i]] = i;
    }

    int ans = 0;
    deque<pair<int,int>> q;
    forr(i,0,n)
    {
        int paso = 0;
        while (!q.empty() && q.back().fst < a[i])
        {
            paso = max(paso, q.back().snd);
            q.pop_back();
        }
        if(q.empty()) paso = 0;
        else paso++;
        q.push_back({a[i],paso});
        ans = max(ans,paso);
    }

    cout << ans << nl;
    
    return 0;
}