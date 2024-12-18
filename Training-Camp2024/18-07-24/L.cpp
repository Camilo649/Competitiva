#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; ++i)
#define ll long long
#define vi vector<int>
#define rec(i, a, b) for(int i=a; i<b; ++i)
#define revn(i, n) for(int i=n-1; i>=0; --i)
#define bg(d) d.begin()
#define ed(d) d.end()
#define range(d) bg(d), ed(d)
#define sz(d) d.size()
#define f first
#define s second
#define printd(d) for(auto e : d) cout << e << ' '; cout << '\n';
#define pii pair<int, int>
#define nl cout<<"\n"
#define ws cout<<" "
//#define MAT
using namespace std;
const int MAX = 2020;
int main()
{
    #ifdef MAT
        freopen("input.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    if(x>=n){
        cout << -1; nl ;return 0;
    }
    int mz[MAX][2*MAX];
    int c=1;
    forn(i, n){
        forn(j, x){
            mz[i][j] = c;
            ++c;
        }
    }
    c=1;
    forn(i, n){
        forn(j, x){
            mz[((i+j+1)%n)][j+x] = c;
            ++c;
        }
    }
    forn(i, n){
        forn(j, 2*x){
            cout << mz[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}