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
        int n,x,y; cin >> n >> x >> y;
        int p[n]; forn(i,n) cin >> p[i];

        vector<int> in, out;
        forn(i,x) in.pb(p[i]);
        forr(i,x,y) out.pb(p[i]);
        forr(i,y,n) in.pb(p[i]);

        int mn = 2e5 + 4;
        int min_pos = -1;
        forn(i,out.size())
        {
            if(mn>out[i])
            {
                mn = out[i];
                min_pos = i;
            }
        }
        vector<int> block2;
        forn(i,out.size())
        {
            block2.pb(out[(i+min_pos)%out.size()]);
        }

        vector<int> ans;
        if(in.empty()) ans = block2;
        else if(block2.empty()) ans = in;
        else if(in[0] < block2[0])
        {
            int j = 0;
            while(j<(int)in.size() && in[j] < block2[0])
            {
                ans.pb(in[j]);
                j++;
            }
            forn(i,block2.size()) ans.pb(block2[i]);
            forr(i,j,in.size()) ans.pb(in[i]);
        }
        else
        {
            ans = block2;
            forn(i,in.size()) ans.pb(in[i]);
        }

        forn(i,n)
        {
            cout << ans[i] << " ";
        }
        cout << nl;
    }
    
    return 0;
}