#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; ++i)
#define ll long long
#define vi vector<int>
#define rec(i, a, b) for(int i=a; i<b; ++i)
#define revn(i, n) for(int i=n-1; i>=0; --i)
#define b(d) d.begin()
#define e(d) d.end()
#define range(d) b(d), e(d)
#define pa printf("a\n")
#define sz(d) d.size()
#define f first
#define s second
#define printd(d) for(auto e : d) cout << e << ' '; cout << '\n';
#define pii pair<int, int>
#define nl cout<<"\n";
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
    ll n, d;
    cin>>n>>d;
    vector<ll> v(n);
    for(auto &a : v){
        cin >> a;
    }
    ll h=2;
    ll last = -100000000000000;
    rec(i, 0, n){
        if(i && v[i]-d >= v[i-1]+d && last != v[i]-d){
            ++h;
        }
        if(i != n-1 && v[i]+d <= v[i+1]-d){
            last = v[i]+d;
            h++;
        }
    }
    cout << h;
    return 0;
}


