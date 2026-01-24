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
#define nl endl;
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;
const double EPS = 1e-10;

using namespace std;
 
int tests;

bool compare(int a, int b)
{
    cout << "?" << " " << a << " " << b << nl;
    int res; cin >> res;
    if(res) return true;
    return false;
}

int main()
{
    // #ifdef MILF
    //     freopen("../input.txt", "r", stdin);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        vector<int> v;
        
        int l = 0 , r = n -1;
        while (a <= b) {
            int k = (a+b )/2;
            if (array [k] == x) {
                // encontre X en indice K
            }
            if (array [k] > x) b = k -1;
            else a = k+1;
        }

        // cout << "!" << " " << a << " " << b << " " << c << nl;
    }
    
    return 0;
}