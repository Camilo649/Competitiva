#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    vector<int> arr;
    ll ans = 0;
    forn(i,n){
        int num; cin>>num;
        arr.pb(num);
        ans += num;
    }

    int mi = 1e9+1;

    forn(i,n){
        int num; cin>>num;
        if(arr[i] < num){
            cout<<-1;
            return 0;
        }
        mi = min(mi,arr[i] - num);
    }
    ans -= mi;

    cout<<ans<<nl;
    return 0;
}