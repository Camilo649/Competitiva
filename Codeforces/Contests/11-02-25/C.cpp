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

ll exp(int b, int e) {
    ll val = 1;
    for (int i = 0; i < e; i++)
    val *= b;
    return val;
}

int solve(string s, int d)
{
    int count = 0;
    ll adder = 0;
    int i = 0;
    while (i<d)
    {
        adder += exp(10,i)*9;
        i++;
    }
    
    ll n = stoi(s);

    i = 0;
    bool flag = false;
    while (i<=10)
    {
        forn(j,s.size())
        {
            if(s[j] == '7')
            {
                flag = true;
                count = i;
                break;
            }
        }

        // forn(j,s.size()-1)
        // {
        //     if(s[j] == '6' &&)
        //     {
        //         flag = true;
        //         count = i+1;
        //         break;
        //     }
        // }

        if (flag)
            break;

        n += adder;
        s = to_string(n);
        i++;
    }

    return flag ? count : 10;
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
        ll n;
        cin >> n;
        string s = to_string(n);

        int count = 10;
        forr(i,1,11)
        {
            count = min(count,solve(s,i));
        }

        cout << count << nl;
    }
    
    return 0;
}