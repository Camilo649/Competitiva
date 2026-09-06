#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 3e7 + 7;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif


int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<pair<int,int>> v;
    forn(i,MAXN) v.pb({-1,-1}); // al que llego, paso que use

    v[0] = {0,1};
    forr(i,1,MAXN)
    {
        if(v[i].fst == -1)
        {
            int step = v[i-1].snd;
            v[i] = {i+step,step};
            //print(i); print(i+step); print(step);
            int j = i;
            while (j+step < MAXN)
            {
                //print(j); print(step);
                int next_step = j*3 - (j+step);
                v[j+step] = {j*3, next_step};
                //print(j+step); print(j*3); print(next_step); 
                j += step;
                step = next_step;
            }
        }
    }

    // forr(i,1,31)
    // {
    //     cout << i << ": " << v[i].fst << " " << v[i].snd << nl;
    // }

    cout << v[n].fst << nl;

    return 0;
}