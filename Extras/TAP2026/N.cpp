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

const ll MAXN = 1e6+6, M = 998244353;
ll F[MAXN], INV[MAXN], FI[MAXN];

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll N,K,A; cin >> N >> K >> A;
    
    if(N==1 && K == 0) {cout << A << nl; return 0;}
    if(N==2 && K == 0) {cout << A*A << nl; return 0;}
    if(N<3 || K > N-2) {cout << 0 << nl; return 0;}

    ll ans = 1;
    ans = (((ans*A)%M)*A)%M;
    //print(ans);
    forn(i,N-K-2) ans = (ans*(A-1))%M;
    //print(ans);
    if(N-2 <= K) {cout << ans << nl; return 0;}

    F[0] = 1; forr(i, 1, MAXN) F[i] = F[i-1]*i %M;
    INV[0] = 1; INV[1] = 1; forr(i, 2, MAXN) INV[i] = M - (ll)(M/i)*INV[M%i]%M;
    FI[0] = 1; forr(i, 1, MAXN) FI[i] = FI[i-1]*INV[i] %M;
     
    //print(F[N-2]); print(INV[K]); print(INV[N-K-2]);
    ans = (((F[N-2] * FI[K])%M * FI[N-K-2])%M * ans)%M;
    //print(ans);

    cout << ans << nl;

    return 0;
}