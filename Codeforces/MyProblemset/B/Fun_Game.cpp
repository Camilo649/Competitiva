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
 
int q;

int main()
{
    #ifdef CAM
        freopen("input.txt", "r", stdin);
    #endif

    cin >> q;
    while (q--)
    {
        int n;
        string s,t;
        cin >> n >> s >> t;

        bool sePuede = true;
        int p = 0;
        while (s[p] == '0' && p<n)
        {
            if (t[p] == '1') {
                sePuede = false;
                break;
            }
            ++p;
        }

        if(sePuede) {cout << "YES" << nl;}
        else cout << "NO" << nl;
    }
    

    return 0;
}