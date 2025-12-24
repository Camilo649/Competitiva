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

const int MAXN = 3 * 1e3 + 9;

using namespace std;
 
int tests;

bool comp(tuple<int,int,int> t1, tuple<int,int,int> t2) {
    return std::get<1>(t1) - std::get<0>(t1) < std::get<1>(t2) - std::get<0>(t2);
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
        int n; cin >> n;
        vector<tuple<int,int,int>> v;
        forn(i,n)
        {
            int a,b; cin >> a >> b;
            v.pb({a,b,i+1});
        }
        sort(v.rbegin(), v.rend(), comp);

        bitset<2*MAXN> added;
        set<int> used;
        for(auto t : v)
        {
            int a,b,i; tie(a, b, i) = t;
            int score = 0;
            forr(j,a,b)
            {
                score += !added[j];
            }
            if (score > 0)
            {
                forr(j,a,b)
                {
                    added[j] = 1;
                }
                used.insert(i);
            }
        }

        cout << used.size() << nl;
        for(auto e : used)
        {
            cout << e << ' ';
        }
        cout << nl;
    }
    
    return 0;
}