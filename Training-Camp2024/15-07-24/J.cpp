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
 
string s;

int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> s;

    ll l,r;
    if (s.size() != 0)
    {
        ll oLeftCount = 0;
        while ((oLeftCount<s.size()) && (s[oLeftCount] == 'o'))
        {
            ++oLeftCount;
        }
        l = oLeftCount;

        ll j = s.size()-1;
        ll oRightCount = 0;
        while ((j>0) && (s[j] == 'o'))
            {
                ++oRightCount;
                --j;
            }

        r = s.size()-oRightCount;
    }

    //cout << s << nl;

    ll k = l;
    ll vs = 0;
    ll os = 0;
    ll total = 0;
    ll opos = 0;
    vector<ll> V;
    V.push_back(0);

    while (k < r)
    {
        while ((k < r)&&(s[k] == 'v'))
        {
            ++vs;
            ++k;
        }
        V.push_back(vs + (V.back()) - 1);
        vs = 0;
        while ((k < r)&&(s[k] == 'o'))
        {
            ++k;
        }
    }
/*
    forn(i,V.size()) {
        cout << V[i] << ' ';
    }
    cout << nl;
*/
    // 0 2 4

    k = l;
    while (k < r) {
        while ((k < r)&&(s[k] == 'v'))
        {
            ++k;
        }
        while ((k < r)&&(s[k] == 'o'))
        {
            ++os;
            ++k;
        }
        if (opos < V.size())
        {
            ++opos;
            total += V[opos]*os*((V.back()) - V[opos]);
        }
        os = 0;
    }

    cout << total << nl;

    return 0;
}