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
        vector<int> v;
        set<int> added; 
        forn(i,n)
        {
            int a;
            cin >> a;
            if(added.count(a) == 0)
            {
                v.pb(a);
                added.insert(a);
            }
        }
        int m = v.size();
        v.pb(1e9 + 6);

        sort(v.begin(), v.end());

        
        int i = 0;
        int mx = 1;
        while(i<m)
        {
            int curr = 0;
            while (i<m && v[i]+1 == v[i+1])
            {
                i++;
                curr++;
            }
            mx = max(mx,curr+1);
            i++;
        }
        cout << mx << nl; 
    }
    
    return 0;
}