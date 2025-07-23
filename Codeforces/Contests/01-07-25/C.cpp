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

const int MAXN = 1000006;

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
        int n;
        cin >> n;
        int a[n];
        int max = 0;
        int min = MAXN;
        forn(i,n) {
            cin >> a[i];
            a[i] > max ? max = a[i] : max = max;
            a[i] < min ? min = a[i] : min = min;
        }

        bitset<MAXN> bs;
        int left_min = MAXN;
        forn(i,n)
        {
            if (left_min > a[i] || a[i] == min)
            {
                bs[i] = 1;
                left_min = a[i];
            }
            else if (a[i] == max)
            {
                bs[i] = 1;
            } 
        }
        
        int right_max = 0;
        dforn(i,n)
        {
            if (right_max < a[i])
            {
                bs[i] = 1;
                right_max = a[i];
            }
        }

        bs[0] = 1;
        bs[n-1] = 1;
        forn(i,n) {
            cout << bs[i];
        }
        cout << nl;
    }
    
    return 0;
}