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

    int n,t; cin >> n >> t;
    int FR[n];
    int FC[n];
    forn(i,n) {FR[i]= i+1; FC[i] = i+1;}
    while(t--)
    {
        char c; int i,j;
        cin >> c >> i >> j;
        if(c == 'R')
        {
            FR[i] = j;
            FR[j] = i;
        }
        else
        {
            FC[i] = j;
            FC[j] = i;
        }
    }

    return 0;
}