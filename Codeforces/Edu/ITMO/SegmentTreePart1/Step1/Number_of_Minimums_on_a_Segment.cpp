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

const int MAXN = 1<<17;
const int INF  = 1e9;

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

int n; 
pair<int,int> t[2*MAXN];
void buildst(int a[]) {
    forn(i,n) t[n+i] = {a[i], 1};
    for (int i = n-1; i > 0; i--)
    {
        int m1 = t[2*i].fst;
        int m2 = t[2*i+1].fst;
        int c1 = t[2*i].snd;
        int c2 = t[2*i+1].snd;
        if(m1 == m2) t[i] = {m1, c1+c2};
        else if (m1 < m2) t[i] = {m1, c1};
        else t[i] = {m2, c2};
    }
}

void updatest(int k, int x) { // posicion del elemento a actualizar en A, nuevo valor
    k += n;
    t[k] = {x,1};
    for (k /= 2; k >= 1; k /= 2) {
        int m1 = t[2*k].fst;
        int m2 = t[2*k+1].fst;
        int c1 = t[2*k].snd;
        int c2 = t[2*k+1].snd;
        if(m1 == m2) t[k] = {m1, c1+c2};
        else if (m1 < m2) t[k] = {m1, c1};
        else t[k] = {m2, c2};
    }
}

pair<int,int> minst(int l, int r) { // indice izquiero del subarbol, indice derecho del subarbol
    l += n; r += n;
    pair<int,int> ans = {INF,1};
    while (l <= r) {
        if (l%2 == 1)
        {
            int m = t[l].fst;
            int c = t[l].snd;
            if(ans.fst == m) ans.snd += c;
            else if(m < ans.fst) ans = t[l];
            l++;
        }
        if (r%2 == 0) 
        {
            int m = t[r].fst;
            int c = t[r].snd;
            if(ans.fst == m) ans.snd += c;
            else if(m < ans.fst) ans = t[r];
            r--;
        }
        l /= 2; r /= 2;
    }
    return ans;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m; cin >> n >> m;
    int size = 1;
    while(size<n) size <<= 1;
    int a[size]; forn(i,n) cin >> a[i];
    forr(i,n,size) a[i] = INF;
    n = size;

    buildst(a);

    // forn(i,2*n)
    // {
    //     cout << t[i] << " ";
    // }

    forn(j,m)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int i,v; cin >> i >> v;
            updatest(i, v);
            // forn(i,2*n)
            // {
            //     cout << t[i] << " ";
            // }
        }
        else
        {
            int l,r; cin >> l >> r;
            cout << minst(l,r-1) << nl;
        }
    }
    
    return 0;
}