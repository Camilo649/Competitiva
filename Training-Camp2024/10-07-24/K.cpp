#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; ++i)
#define ll long long
#define vi vector<int>
#define rec(i, a, b) for(int i=a; i<b; ++i)
#define revn(i, n) for(int i=n-1; i>=0; --i)
#define b(d) d.begin()
#define e(d) d.end()
#define range(d) b(d), e(d)
#define pa printf("a\n")
#define sz(d) d.size()
#define pii pair<int, int>
const int MAX = 110;
//#define MAT
using namespace std;

int main()
{
    #ifdef MAT
        freopen("input.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vi v(n);
    forn(i, n){
        cin >> v[i];
    }
    int m, k;
    int mz[MAX][MAX];
//    set<pair<int, int>>s;
//    forn(i, n){
//        s.insert(pii(v[i], -i));
//    }
    forn(j, n){
        mz[n-1][j] = v[j];
    }
//    for(auto e:s){
//        cout << e.first << ' ' << e.second << "\n";
//    }cout << endl;
//    auto it = s.begin();
//    for(int i=n-2; i>=0; --i){
//        int j=0, k=0;
//        for(; j<=i; ++j){
//            if(k == -(it->second))++k;
//            mz[i][j] = mz[i+1][k];
//            ++k;
//            cout << k << ' ';
//        }
//        cout << '\n';
//        ++it;
//    }
//    cin >> m;
    for(int i=n-2; i>=0; --i){
        int mn = 1e9;
        int pmn = i;
        for(int j=i+1; j>=0; --j){//busco el menor
            if(mn > mz[i+1][j]) {
                mn =  mz[i+1][j];
                pmn = j;
            }
        }
        int k=0, j=0;
        for(; j<i+1; ++j){
            if(k == pmn)++k;
            mz[i][j] = mz[i+1][k];
            ++k;
            
        }
    }
//    forn(i, n){
//        forn(j, n){
//            cout << mz[i][j] << ' ';
//        }cout << endl;
//    }
    cin>>m;
    forn(i,m){
        int x, y;
        cin >> x >> y;
        cout << mz[x-1][y-1] << "\n";
    }
    
//    forn(i, m)
    
    return 0;
}


