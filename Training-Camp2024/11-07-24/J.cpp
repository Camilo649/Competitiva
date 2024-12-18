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
const int MAXN = -1;                                              // Redefinir a gusto para el maximo del arreglo 
 
int n;
int k;
string s;
 
int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif
 
    cin >> n >> k;
    int A[n];
    forn(i, n){
        cin >> A[i];
    }
    cin >> s;
 
    
    ll dmg = 0;
    int l;
    forn(i, n) {
        char c = s[i];
        multiset<int>t;
        
        l = i;
        while (c == s[l])
        {
            t.insert(A[l]);
            ++l;
        }
        
        int counter = k;
        while (!t.empty() && counter != 0)
        {
            auto e = --t.end();
            dmg += *e;
            t.erase(e);
            --counter;
        }
        i=(l-1);
    }
 
    cout << dmg << nl;
    return 0;
}