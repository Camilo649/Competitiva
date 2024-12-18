#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)
#define ll long long
#define vi vector<int>
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
    
    int t;
    cin >> t;
    while(t--){
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        ll mx=0;
        mx = max(mx, abs(1-a)+abs(1-b));
        mx = max(mx, abs(x-a)+abs(1-b));
        mx = max(mx, abs(1-a)+abs(y-b));
        mx = max(mx, abs(x-a)+abs(y-b));
        cout << mx << '\n';
    }
    
    return 0;
}