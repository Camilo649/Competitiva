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
        ll u, v;
        cin >> u >> v;
        cout << -u*u << ' ' << v*v << '\n';
    }
    
    
    return 0;
}
 