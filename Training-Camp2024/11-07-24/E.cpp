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
    
    int t;
    cin >> t;
    string m = "meow";
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int i=0;
        if(tolower(s[i]) == m[0]){
            while(tolower(s[i]) == m[0])++i;
        }
        else{
            cout << "NO\n";
            continue;
        }
        if(tolower(s[i]) == m[1]){
            while(tolower(s[i]) == m[1])i++;
        }
        else{
            cout << "NO\n";
            continue;
        }
        if(tolower(s[i]) == m[2]){
            while(tolower(s[i]) == m[2])i++;
        }
        else{
            cout << "NO\n";
            continue;
        }
        if(tolower(s[i]) == m[3]){
            while(tolower(s[i]) == m[3])i++;
        }
        else{
            cout << "NO\n";
            continue;
        }
        if(i==s.size())cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}