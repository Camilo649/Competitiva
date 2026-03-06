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
 
int tests;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int k; cin >> k;
        int a1,a2,b1,b2; cin >> a1 >> b1 >> a2 >> b2;

        int Around = 0;
        int Bround = 0;
        int Ascore = 0;
        int Bscore = 0;

        if(a1 > b1) Around++;
        else if(b1 > a1) Bround++;
        Ascore += a1; Bscore += b1;
        if(a2 > b2) Around++;
        else if(b2 > a2) Bround++;
        Ascore += a2; Bscore += b2;

        if(Bscore > Ascore) cout << "YES";
        else if(Bscore == Ascore)
        {
            cout << ((Bround > 0) ? "YES" : "NO");
        }
        else
        {
            cout << ((Ascore-Bscore < k || (Ascore-Bscore == k &&  Bround > 0)) ? "YES" : "NO");
        }

        cout << nl;
    }
    
    return 0;
}