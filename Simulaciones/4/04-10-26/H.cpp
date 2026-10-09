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

const int MAXN = 308;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<string> names(n);
    forn(i,n) cin >> names[i];

    map<string,int> name_to_id;
    forn(i,n) name_to_id[names[i]] = i;    // id_to_name es simplemente names[id]

    vector<bitset<MAXN>> pos(n);
    forn(i,n) forn(j,n) pos[i][j] = 1;

    int R; cin >> R;
    forn(k,R)
    {
        int m, w; cin >> m >> w; w--;
        bitset<MAXN> b;
        forn(j,m){
            string t; cin >> t;
            b[name_to_id[t]] = 1;
        }
        forn(i,n)
        {
            if(b[i]) forn(j,w) pos[j][i] = 0;
            else     pos[w][i] = 0;
        }
    }

    bitset<MAXN> placed;
    vector<string> ans;
    forn(i,n)
    {
        bitset<MAXN> cand = pos[i] & ~placed;
        int j = cand._Find_first();        // menor id disponible en esta posición
        placed[j] = 1;
        ans.pb(names[j]);
    }

    forn(i,n) cout << ans[i] << " ";
    cout << nl;

    return 0;
}