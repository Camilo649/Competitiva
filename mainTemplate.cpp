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

const int MAXN = -1;
const double EPS = 1e-5;

using namespace std;
 
int tests;

double reduce(vector<vector<double>> &a){  //Devuelve determinante si m == n
	int m = sz(a), n = sz(a[0]);
	int i = 0, j = 0;
	double r = 1.0;
	while(i < m and j < n){
		int h = i;
		forr(k, i+1, m) if(abs(a[k][j]) > abs(a[h][j])) h = k;
		if(abs(a[h][j]) < EPS){
			j ++;
			r = 0.0;
			continue;
		}
		if(h != i){
			r = -r;
			swap(a[i], a[h]);
		}
		r *= a[i][j];
		dforr(k, j, n) a[i][k] /= a[i][j];
		forr(k, 0, m){
			if(k == i) continue;
			dforr(l_, j, n) a[k][l_] -= a[k][j] * a[i][l_];
		}
		i ++; j ++;
	}
	return r;
}

vector<vector<double>> build_laplacian(int n, const vector<pair<int,int>> &edges)
{
    vector<vector<double>> L(n, vector<double>(n, 0.0));

    for(auto [u, v] : edges){
        L[u][u] += 1;
        L[v][v] += 1;
        L[u][v] -= 1;
        L[v][u] -= 1;
    }
    return L;
}

vector<vector<double>> cofactor(const vector<vector<double>> &L)
{
    int n = sz(L);
    vector<vector<double>> M(n-1, vector<double>(n-1));

    forr(i, 1, n)
        forr(j, 1, n)
            M[i-1][j-1] = L[i][j];

    return M;
}

long long count_spanning_trees(int n, const vector<pair<int,int>> &edges)
{
    auto L = build_laplacian(n, edges);
    auto M = cofactor(L);

    double det = reduce(M);

    return llround(det);
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 4;
vector<pair<int,int>> edges = {
    {0,1},
    {0,2},
    {0,3},
    {2,3}
};


    cout << count_spanning_trees(n, edges) << nl;
    
    return 0;
}