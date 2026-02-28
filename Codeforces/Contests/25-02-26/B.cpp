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

int sum_digits(string x)
    {
        int sum = 0;
        forn(i,x.size()) sum += x[i] - '0';
        return sum;
    }

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
        string x; cin >> x;

        char fst = x[0];
        sort(x.rbegin(), x.rend());
        int idx = -1;
        dforn(i,x.size())
        {
            if(x[i] == fst)
            {
                idx = i;
                break;
            }
        }
        int ans = 0;
        int i = 0;
        while (sum_digits(x) >= 10)
        {
            if(i == idx && x[idx] != '1') 
            {
                x[idx] = '1';
                ans++;
            }
            else if(x[i] != '0')
            {
                x[i] = '0';
                ans++;
            }
            i++;
        }
        
        cout << ans << nl;
    }
    
    return 0;
}