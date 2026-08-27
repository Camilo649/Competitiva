#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e5+6;

using namespace std;

ll memory[200][MAXN] = {};
bool visited[200][MAXN] = {};
ll n; ll p;
vector<tuple<ll,ll,ll>> arr;

ll dp(ll pos, ll p){
    ll A = get<1>(arr[pos]);
    ll B = get<0>(arr[pos]);
    ll C = get<2>(arr[pos]);
    if(pos==n) return 0;

    if(visited[pos][p]){
        return memory[pos][p];
    }

    ll ans = dp(pos+1,p);

    if(p>=B){
        ll np = (p-B)/A;
        ans = max(ans,C+dp(pos+1, np));
    }
    // forr(u, pos+1,n){
    //     if(pm>0){
    //         ll ppm = dp(u, pm);
    //         ans = max(ans,ppm+C);
    //     }
    //     ll ppnm = dp(u,p);
    //     ans = max(ans,ppnm);

    // }
    memory[pos][p] = ans;
    visited[pos][p] = 1;
    return ans;
}

bool comp(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b) {
    ll Ba = get<0>(a), Aa = get<1>(a);
    ll Bb = get<0>(b), Ab = get<1>(b);
    return Ba*(Ab-(ll)1) > Bb*(Aa-(ll)1);
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>p;

    forn(i,n){
        ll A; ll B; ll C; cin>>A>>B>>C;
        arr.pb({B,A,C});
    }

    sort(ALL(arr),comp);
    ll ans = 0;
    forn(i,n){
        ans = max(ans, dp(i,p));
    }
    
    cout<<ans<<nl


    
    return 0;
}