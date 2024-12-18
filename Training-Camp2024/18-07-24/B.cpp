#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; ++i)
#define ll long long
#define vi vector<ll>
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
#define ws cout<<" "
//#define MAT
using namespace std;
 
int main()
{
    #ifdef MAT
        freopen("input.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    vi v(3);
    cin>>v[0]>>v[1]>>v[2];
    ll d = *max_element(range(v))-1;
    if(d<1){
        cout << 0;nl;return 0;
    }
    ll p=0;
    forn(i, 3){
        v[i]-=d;
    }
    forn(i, 3){
        if(v[i]<0)
            p-=v[i];
    }
    cout << p ;nl;
    return 0;
}