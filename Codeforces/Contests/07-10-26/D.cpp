#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;
const ll INF = LONG_LONG_MAX;

using namespace std;

// Debugging
#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    if (DBG) os << "[";
    for (auto& x : v) os << x << (DBG ? ", " : " ");
    return DBG ? os << "]" : os;
}

template<typename S, typename T> ostream& operator<<(ostream& os, const pair<S, T>& p) {
    return os << (DBG ? "(" : "") << p.fst << (DBG ? ", " : " ") << p.snd << (DBG ? ")" : "");
}

int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;
    
    while (tests--)
    {
        ll n,k; cin >> n >> k;
        ll arr[n][3]; forn(i,n) {cin >> arr[i][0] >> arr[i][1] >> arr[i][2];}

        vector<pair<ll, tuple<ll,ll,ll>>> sums;
        forn(i,n)
        {
            sums.pb({arr[i][0] + arr[i][1] + arr[i][2],{arr[i][0],arr[i][1],arr[i][2]}});
        }

        sort(ALL(sums));

        sums.pb(sums.back());

        ll UB = LONG_LONG_MAX; // Limite superior 
        ll LB = sums[0].fst;   // Limite inferior
        forn(i,n)
        {
            ll a = get<0>(sums[i].snd), b = get<1>(sums[i].snd), c = get<2>(sums[i].snd);

            //print(1);print(k);
            //print(a); print(b); print(c);
            if(a==b && b==c) {UB = min(UB, sums[i].fst); continue;}
            else if((a==b && a<c) || (b==c && a<c)) k-=2;
            else if(a<b && b<c) k -= 2*(min(b-a+1, c-b+1));

            //print(2);print(k);
            if(k<=0) break;

            ll add = sums[i+1].fst-sums[i].fst;
            //print(add);
            LB += min(k/(i+1), add); 
            k-=(i+1)*add;
            //print(3);print(k);
            if(k<=0) break;
        }

        if(k>0) LB += k/n;

        cout << min(LB,UB) << nl;
    }
    
    return 0;
}