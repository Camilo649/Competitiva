#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second 
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,h,w; cin >> n >> h >> w;
    forn(i,n)
    {
        char c1,c2; cin >> c1 >> c2;
        if(c1 == 'Y' || w == 0)
        {
            cout << "Y ";
            h--; w++; 
        }
        else
        {
            cout << "N ";
        }

        if(c2 == 'Y' || h == 0)
        {
            cout << "Y ";
            w--; h++; 
        }
        else
        {
            cout << "N";
        }
        cout << nl;
    }

    return 0;
}