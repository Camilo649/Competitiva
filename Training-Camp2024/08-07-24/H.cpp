#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)
#define ll long long
#define vi vector<int>
#define MAT
using namespace std;
 
int main()
{
    #ifdef MAT
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    string h = "hello";
    int j=0;
    forn(i, s.size()){
        if(s[i] == h[j]) j++;
        if(j==5)break;
    }
    if(j==5) cout << "YES\n";
    else cout << "NO\n";
    
    
    return 0;
}