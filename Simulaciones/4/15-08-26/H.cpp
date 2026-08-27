#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) sort(x.begin(), x.end())
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

int hashing(string s)
{
    int mul = 1;
    int ans = 0;
    dforn(i,SZ(s))
    {
        ans += s[i]*mul;
        mul *= 31;
    }

    return ans;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    string s;
    forn(i,n) s += 'H';

    s[0] += 1;
    cout << s << nl;
    //cout << hashing(s) << nl

    forr(i,1,n)
    {
        s[i-1] -= 1;
        s[i] += 31;
        cout << s << nl;
        //cout << hashing(s) << nl
    }


    
    return 0;
}