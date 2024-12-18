#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; ++i)
#define ll long long
#define vi vector<int>
#define rec(i, a, b) for(int i=a; i<b; ++i)
#define revn(i, n) for(int i=n-1; i>=0; --i)
#define bg(d) d.begin()
#define ed(d) d.end()
#define range(d) bg(d), ed(d)
#define sz(d) d.size()
#define f first
#define s second
#define printd(d) for(auto e : d) cout << e << ' '; cout << '\n';
#define pii pair<int, int>
#define nl cout<<"\n"
#define ws <<" "<<
//#define MAT
const int MAXN = -1;

using namespace std;

int t;

int main()
{
    #ifdef MAT
        freopen("input.in", "r", stdin);
    #endif
    vector<vector<ll>>mz(19);
    int x=1, y=1, z=0;
    forn(i,19){
        y=1, z=0;
        mz[i].resize(200005);
        rec(j,x,200005){
            mz[i][j]=(mz[i][j-1]+(1*y));
            ++z;
            if(z==x){
                z=0;
                if(y)y=0;
                else y=1;
            }
        }
        x*=2;
    }
    cin >> t;
    while (t--)
    {
        int l,r;
        cin >> l >> r;
        ll mx=0;
        forn(i, 19){
            mx = max(mx, mz[i][r]-mz[i][l-1]);
        }
        cout<<(r-l+1)-mx;nl;
    }
    
    return 0;
}
