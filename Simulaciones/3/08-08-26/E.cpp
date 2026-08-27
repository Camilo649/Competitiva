#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)

#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 105;

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

    string s[2], t[2];
    cin >> s[0] >> s[1] >> t[0] >> t[1];

    int n = SZ(s[0]);

    vector<pair<char,char>> v[2];
    forn(i,n)
    {
        v[0].pb({s[0][i], s[1][n-(i+1)]});
        v[1].pb({t[0][i], t[1][n-(i+1)]});
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());

    if(v[0] == v[1]) cout << "Yes";
    else cout << "No";

    cout << nl
    
    return 0;
}