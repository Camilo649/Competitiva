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

using namespace std;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int Y,W; cin >> Y >> W;

    int num;
    int mx = max(Y,W);
    mx--;
    num = 6 - mx;

    if(num == 0) cout << 0 << '/' << 1;
    else if(num == 2) cout << 1 << '/' << 3;
    else if(num == 3) cout << 1 << '/' << 2;
    else if(num == 4) cout << 2 << '/' << 3;
    else if(num == 6) cout << 1 << '/' << 1;
    else cout << num << '/' << 6;

    cout << nl;
    
    return 0;
}