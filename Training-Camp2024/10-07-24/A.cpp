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
    
    int n;
    cin >> n;
    int x;
    map<int, int>m;
    forn(i, n){
        cin >> x;
        m[x] = i+1; 
    }
    if(m.size()>=3){
        auto it = m.begin();
        forn(i, 3){
            cout << it->second << ' ';
            it++;
        }
            cout << '\n';
    }
    else 
       cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
    
    return 0;
}