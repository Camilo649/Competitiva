#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k,n; cin>>k>>n;

    if (n < 2*k-1 || n > 3*k){
        cout << '*' << nl;
    }
    else if(n == 2*k-1){
        cout << 'X';
        forn(i, k-1){cout << "-X";}
        cout << nl;
    }
    else if(n == 2*k){
        forn(i, k){ cout << "X-";}
        cout << nl;
    }
    else {
        cout << '-';
        int k2 = n-k-(k+1);
        forn(i, k2){cout << "X--";}
        forn(i, k-k2){cout << "X-";}
        cout << nl;
    }


    return 0;
}