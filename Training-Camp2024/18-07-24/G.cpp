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
#define nl cout<<"\n";
#define ws <<" "<<
//#define MAT
using namespace std;
typedef long double ld;

int main()
{
    #ifdef MAT
        freopen("input.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int n, R; cin>>n>>R;
    int sr = R*R;
    vi x(n);
    forn(i, n){
        cin>>x[i];
    }
    vector<pair<int, ld>> ans(n);
    forn(i, n){
        int l=x[i]-R, r=x[i]+R;
        if(l<0) l=0;
        if(r>1000) r=1000;
        ld cx=0, cy=0, mx=R;
        ans[i].f=x[i];
        forn(j, n){
            if(ans[j].s==0)break;
            if(ans[j].f==ans[i].f){
                // cout << R ws ans[i].s;nl;
                mx = max(mx, (ld)R*2+ans[j].s);
                continue;
            }
            cx = ans[j].f;
            cy = ans[j].s;
            ld dy = 4*R*R-abs(cx-x[i])*abs(cx-x[i]);
            mx = max(mx, cy+sqrtl(dy));

        }
        ans[i].s = mx;
    }
    forn(i, n){
        cout<<fixed<<setprecision(11)<< ans[i].second << ' ';
    }nl;

    return 0;
}

