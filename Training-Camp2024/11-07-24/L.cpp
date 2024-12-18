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
//#define MAT 
// redefiniciones 
typedef long long ll; 
typedef long double ld; 
 
using u64 = uint64_t; 
using namespace std;               
int main() 
{ 
#ifdef MAT 
    freopen("input.in", "r", stdin); 
#endif 
    int n;
    cin >> n; 
    
    ll x, y; 
    while(n--) 
    { 
        cin >> x >> y; 
        ll r = abs(x-y); 
        if (r>1){
            cout << "YES" << nl; 
        }
        else 
            cout << "NO" << nl; 
    } 
    
    return 0; 
}