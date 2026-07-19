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
        int n,k; cin  >> n >> k;
        int a[k]; forn(i,k) cin >> a[i];
        priority_queue<pair<int,int>> b; 
        forn(i,n)
        {
            int val;
            cin >> val;
            if(val != k+1) b.push({val,i+1});
        }

        vector<int> ans;
        int m = 0 ;
        while (!b.empty() && m<1000)
        {
            auto e = b.top(); b.pop();
            e.first++;
            ans.pb(e.second);
            if(e.first != k+1) b.push(e);

            m++;
        }
        
        if(b.empty())
        {
            cout << m << nl;
            forn(i,m)
            {
                cout << ans[i] << " ";
            }
            cout << nl;
        }
        else cout << -1 << nl;
    }
    
    return 0;
}