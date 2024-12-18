#include<bits/stdc++.h>
 
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
#define MAT
// redefiniciones
typedef long long ll;
typedef long double ld;
 
using u64 = uint64_t;
using namespace std;
const int MAXN = 10010;
 
int n;
 
int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif
 
    cin >> n;
 
    int A[MAXN];
 
    forn(i,n) {
        cin>>A[i]; 
    }
 
    int days = 1;
    int mx = A[0];
    forn(i, n) {
        if ((i+1) > mx)
        {
           ++days;
        }
        mx = max(mx, A[i]);
    }
    
    cout << days << nl;
 
    return 0;
}