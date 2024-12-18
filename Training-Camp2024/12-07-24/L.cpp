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
 
int main()
{
    #ifdef MAT
        freopen("input.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
        int a, b, c, x, y, z;
        cin >> a >> b >> c >> x >> y >> z;
        a-=x;
        b-=y;
        c-=z;
        if(a>=0 && b>=0 && c>=0) cout << "Yes\n";
        else{
            if(a>0)a/=2;
            if(b>0)b/=2;
            if(c>0)c/=2;
            if(a+b+c >= 0){
                cout << "Yes\n";
                return 0;
            }
            cout <<"No\n";
        }
    return 0;
}