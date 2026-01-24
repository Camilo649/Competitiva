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
        string s; cin >> s;

        string t = s.substr(0,n);
        sort(t.begin(), t.end());
        if(s==t) cout << "Bob";
        else
        {
            vector<int> indexes;
            
            forn(i,n)
            {
                if(s[i] != t[i]) indexes.pb(i);
            }

            cout << "Alice" << nl;
            int m = indexes.size();
            cout << m << nl;
            forn(j, m)
            {
                cout << indexes[j] + 1 << " ";
            }
        }
        cout << nl;
    }
    
    return 0;
}