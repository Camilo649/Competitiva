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
#define MAT
using namespace std;

int main()
{
#ifdef MAT
    freopen("../input.txt", "r", stdin);
#endif

    
    ll t;
    cin>>t;

    while(t--){
        ll n;string s;
        cin>>n>>s;
        ll i=0;
        if ((s[i] != s[i+1])){
            while((i<n) && (s[i] >= s[i+1])) {
                ++i;
            }
        }
        string res = s.substr(0,i+1);
        string p=res;
        reverse(range(p));
        res+=p;
        cout << res << endl;
    }
    
    return 0;
}
