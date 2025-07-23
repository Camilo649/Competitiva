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
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e5 + 6;
const double EPS = 1e-10;
const ll K = 17;

using namespace std;
 
int tests;

#define oper min
int st[K][1<<K];int n;  // K such that 2^K>n
void st_init(int *a){
	forr(i,0,n)st[0][i]=a[i];
	forr(k,1,K)forr(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >>n;
    int h[n];
    forn(i,n)
    {
        cin >> h[i];
    }

    st_init(h);

    int m; cin >> m;
    forn(i,m)
    {
        int l,r,w; cin >> l >> r >> w;
        cout << st_query(l,r) << nl;
    }

    return 0;
}