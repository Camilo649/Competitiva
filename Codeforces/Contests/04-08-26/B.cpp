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
#define GG
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
        int n; cin >> n;
        string s; cin >> s;

        bool flag1 = false;
        forr(i,1,n-1)
        {
            if(s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] == s[i+1]) flag1 = true;
        }

        bool flag2 = false;
        forr(i,1,n-1)
        {
            if(s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] != s[i+1]) flag2 = true;
        }

        int count = 0;
        forn(i,n)
        {
            count++;
            while(s[i] == s[i+1]) i++;
        }

        if(flag1) count -= 2;
        else if(flag2) count--;

        cout << count << nl;
    }
    
    return 0;
}