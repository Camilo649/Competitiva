#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for (int i=0;i < int (n) ; i++)
#define vi vector<int>
#define MILF

const int INF=1e4+5;


int main() {
    // #ifdef MILF
    //     freopen("../input.txt", "r", stdin);
    // #endif
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<vi>a(n, vi(m));
    forn(i, n) forn(j, m) cin >> a[i][j];
    int r, s; cin >> r >> s;

    int n2=n-r+1,m2=m-s+1;
    vector<vi>ans(n2,vi(m2));
    forn(i,n2) forn(j,m2) ans[i][j] = -INF;

    forn(i, n2) {
        forn(j, m2) {
            for(int k = i; k<i+r; k++)
            {
                for(int l = j; l<j+s; l++)
                {
                    ans[i][j] = max(ans[i][j],a[k][l]);
                }
            }
        }
    }

    forn(i, n2) {
        forn(j, m2) {cout << ans[i][j]<<" ";}
        cout<<"\n";
    }

    return 0;
}