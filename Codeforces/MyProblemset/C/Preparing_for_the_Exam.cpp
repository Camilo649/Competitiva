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

const int MAXN = 3 * 1e5;

using namespace std;
 
int t;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;

    while (t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        int list[m];
        forn(i,m)
        {
            cin >> list[i];
        }
        set<int> answer;
        forn(i,k)
        {
            int a;
            cin >> a;
            answer.insert(a);
        }

        bitset<MAXN> b;
        if (n-k >= 2)
        {
            forn(i,m)
            {
                cout << b[i];
            }
        }
        else if (n-k == 1)
        {
            forn(i,m)
            {
                if (answer.count(list[i]) == 0)
                {
                    b[i] = 1;
                }
                cout << b[i];  
            }
        }
        else
        {
            forn(i,m)
            {
                b[i] = 1;
                cout << b[i];
            }
        } 
        cout << nl;
    }
    

    return 0;
}