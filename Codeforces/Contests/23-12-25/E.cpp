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

const int MAXN = 2*1e5 + 6;

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
        int n,x,y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        bitset<MAXN> b(s);
        int p[n];
        forn(i,n) cin >> p[i];
        bool flag = true;

        ll sum = 0;
        ll lbA = 0, difA = 0, voteA = 0;
        ll lbB = 0, difB = 0, voteB = 0;
        // bool existEvenA = false;
        // bool existEvenB = false;
        forn(i,n)
        {
            sum += p[i];
            if(s[i] == '0')
            {
                lbA += p[i]/2 + 1;
                // if(p[i]%2 == 0)
                // {
                //     difA += 2;
                //     //existEvenA = true;
                // }
                // else difA += 1;
                // voteA += p[i];
            }
            else
            {
                lbB += p[i]/2 + 1;
                // if(p[i]%2 == 0)
                // {
                //     difB += 2;
                //     //existEvenB = true;
                // }
                // else difB += 1;
                // voteB += p[i];
            }
        }
        // if(difA > difB)
        // {
        //     if(x - difA < y - difB) flag = false;
        // }
        // else
        // {
        //     if(y - difB < x - difA) flag = false;
        // }
        if(x+y < sum) flag = false;
        if(b.count() == 0)
        {
            if(!(x >= y+n && x >= lbA)) flag = false;
        }
        else if(b.count() == (size_t)n)
        {
            if(!(y >= x+n && y >= lbB)) flag = false;
        }
        else
        {
            if(x<lbA || y<lbB) flag = false;
        }

        if(flag)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << nl;
    }
    
    return 0;
}