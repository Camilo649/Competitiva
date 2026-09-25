#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 2<<17; // ~2e5

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

int r;

struct item{
    int m[2][2];
};

item matrix_product(item a, item b)
{
    item ans;
    ans.m[0][0] = ((a.m[0][0]*b.m[0][0])%r + (a.m[0][1]*b.m[1][0])%r)%r;
    ans.m[0][1] = ((a.m[0][0]*b.m[0][1])%r + (a.m[0][1]*b.m[1][1])%r)%r;
    ans.m[1][0] = ((a.m[1][0]*b.m[0][0])%r + (a.m[1][1]*b.m[1][0])%r)%r;
    ans.m[1][1] = ((a.m[1][0]*b.m[0][1])%r + (a.m[1][1]*b.m[1][1])%r)%r;
    return ans;
} 

int n; 
item t[2*MAXN];

void buildst(int a[][2][2]) {
    forn(k,n) 
    {
        forn(i,2)
        {
            forn(j,2)
            {
                t[n+k].m[i][j] = a[k][i][j];
            }
        }
    }
    for (int i = n-1; i > 0; i--)
    {
        t[i] = matrix_product(t[2*i],t[2*i+1]);
    }
}

// void updatest(int k, int x[2][2]) { // posicion del elemento a actualizar en A, nuevo valor
//     k += (ll)n;
//     forn(i,2)
//     {
//         forn(j,2)
//         {
//             t[n+k].m[i][j] = x[i][j];
//         }
//     }
//     for (k /= 2; k >= 1; k /= 2) {
//         t[k] = matrix_product(t[2*k],t[2*k+1]);
//     }
// }

item prodst(int l, int r) { // indice izquiero del subarbol, indice derecho del subarbol
    l += n; r += n;
    item left, right;
    left.m[0][0] = 1; right.m[0][0] = 1;
    left.m[0][1] = 0; right.m[0][1] = 0;
    left.m[1][0] = 0; right.m[1][0] = 0;
    left.m[1][1] = 1; right.m[1][1] = 1;
    while (l <= r) {
        if (l%2 == 1) left = matrix_product(left,t[l++]);
        if (r%2 == 0) right = matrix_product(t[r--],right);
        l /= 2; r /= 2;
    }
    return matrix_product(left,right);
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m; cin >> r >> n >> m; 
    int size = 1;
    while(size<n) size<<=1;
    int a[size][2][2];
    forn(k,n) 
    {
        forn(i,2)
        {
            forn(j,2)
            {
                cin >> a[k][i][j];
            }
        }
    }

    // Matriz Identidad
    forr(k,n,size)
    {
        a[k][0][0] = 1;
        a[k][0][1] = 0;
        a[k][1][0] = 0;
        a[k][1][1] = 1;
    }
    n = size;
    
    buildst(a);

    //forn(i,2*n) print(t[i]);

    forn(j,m)
    {
        int l,r; cin >> l >> r;
        item ans = prodst(l-1,r-1);
        forn(i,2)
        {
            forn(j,2)
            {
                cout << ans.m[i][j] << " ";
            }
            cout << nl;
        }
        cout << nl;
    }
    
    return 0;
}