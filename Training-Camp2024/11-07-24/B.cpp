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
//#define MAT
using namespace std;
vi v;
int n;
 
int main()
{
    #ifdef MAT
        freopen("input.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    bool flag = false;
    vi v(4);
    int sum=0;
    forn(i, 4){
        cin >> v[i];
        sum+=v[i];
    }
    forn(i, 4){
        if(sum-v[i] == v[i]) flag = true;
    }
    forn(i, 4){
        rec(j, i+1, 4){
            int x=v[i]+v[j];
            if(x == sum-x) flag = true;
        }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}