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

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<string> names(N);
    forn(i, N) cin >> names[i];
    sort(ALL(names));                          // orden alfabético, como el map

    map<string,int> id;
    forn(i, N) id[names[i]] = i;

    vector<int> lo(N, 1);                      // cota inferior de posición
    vector<vector<char>> ban(N, vector<char>(N + 2, 0));

    int Q; cin >> Q;
    forn(q, Q) {
        int R, W; cin >> R >> W;
        vector<char> in(N, 0);
        forn(i, R) { string s; cin >> s; in[id[s]] = 1; }

        forn(h, N) {
            if (in[h]) lo[h] = max(lo[h], W);  // posiciones 1..W-1 prohibidas
            else       ban[h][W] = 1;          // posición W prohibida
        }
    }

    vector<char> placed(N, 0);
    vector<string> ans;
    forr(p, 1, N + 1) {
        forn(h, N) {
            if (!placed[h] && lo[h] <= p && !ban[h][p]) {
                placed[h] = 1;
                ans.pb(names[h]);
                break;
            }
        }
    }

    for (auto& s : ans) cout << s << " ";
    cout << nl;
}