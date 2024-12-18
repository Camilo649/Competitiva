#include<bits/stdc++.h>
// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; i++)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
//#define MAT   
// redefiniciones
typedef long long ll;
typedef long double ld;
//typedef pair<int, int> ii;                                          
 
int n;

using namespace std; 

const int MAXN = 1e8 + 10;  // Redefinir a gusto para el maximo del arreglo
bitset<MAXN> A;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int d, e;
    cin >> n >> d >> e;

    A[0] = 1;
    forr(i, 0, n) {
        if (A[i] == 1)
        {
            A[i + d] = 1;
            A[i + (5*e)] = 1;        
        }
    }

    dforr(i, 0, n+1) {
        if (A[i] == 1)
        {
            cout << (n - i) << '\n';
            return 0;
        }
        
    }
    
    return 0;
}