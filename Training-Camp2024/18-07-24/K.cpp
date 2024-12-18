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
    int n, k;
    cin>>n>>k;
    vi v(k);
    string s;cin>>s;
    forn(i, n){
        ++v[s[i]-'A'];
    }
    int mn = *min_element(range(v));
    cout << mn*k;nl;
    
    return 0;
}