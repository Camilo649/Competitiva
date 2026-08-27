#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) sort(x.begin(), x.end())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
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
        int n,m; cin >> n >> m;
        set<char> s,a;
        forn(i,n)
        {
            string t; cin >> t;
            s.insert(t[0]);
        }
        forn(i,m)
        {
            string t; cin >> t;
            forn(j,SZ(t)) a.insert(t[j]);
        }

        bool flag = true;
        for(auto it = a.begin(); it != a.end(); it++)
        {
            flag = s.count(*it + 32) == 1;
            if(!flag) break;
        }

        if(flag) cout << "YES";
        else cout << "NO";
        cout << nl
    }
    
    return 0;
}