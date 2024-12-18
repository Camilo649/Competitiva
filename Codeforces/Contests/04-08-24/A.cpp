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
#define CAM
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int t;

int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        int a[4] = {};
        forn(i,s.size()){
            if (s[i]=='?') continue;
            
            if (s[i]=='A')
            {
                a[0]++;
            }
            else if (s[i]=='B')
            {
                a[1]++;
            }
            else if (s[i]=='C')
            {
                a[2]++;
            }
            else
            {
                a[3]++;
            }
        }

        int res = 0;
        forn(i,4){
            res += min(n,a[i]);
        }

        cout << res << nl;
    }
    

    return 0;
}