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
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        string t;
        forn(i,2*n-1)
        {
            if(s[i] == '1' && s[(i+1)%(2*n)] == '0')
            {
                t += "01";
                i++;
            }
            else t += s[i];
        }

        if(s[2*n-1] == '1' && s[0] == '0')
        {
            t[0] = '1';
            t += '0';
        }
        else
        {
            t += s[2*n-1];
        }

        //cout << t << nl

        int red_score = 0, blue_score = 0;
        forn(i,2*n)
        {
            if(i%2 == 1 && t[i] == '1') red_score++;
            if(i%2 == 0 && t[i] == '1') blue_score++;
        }

        cout << red_score << " " << blue_score << nl
    }
    
    return 0;
}