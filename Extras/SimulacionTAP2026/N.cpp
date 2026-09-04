#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i<(int)b; ++i)
#define forn(i,n) forr(i,0,n)

#define dofrr(i,a,b) for(int i = (int) b-1; i>= (int) a; --i)
#define dforn(i,n) dofrr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second 
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;
const int INF = 1e9;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cer << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){
    if(DBG) os << "[";
    for(auto& x : v) os << x << (DBG ? ", " : " ");
    return DBG ? os << "]" : os;
}

template<typename S, typename T> ostream& operator<<(ostream& os, const pair<S, T>& p){
    return os << (DBG ? "(" : "") << p.fst << (DBG ? ", " : " ") << p.snd << (DBG ? ")" : "");
}

int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int x = INF, y = INF, X = -INF, Y= -INF;
    forn(i,n)
    {
        int a,b; cin >> a >> b;
        x = min(a,x);
        X = max(a,X);
        y = min(b,y);
        Y = max(b,Y);
    }

    cout << 2*(Y-y+2) + 2*(X-x+2) << nl;

    return 0;
}