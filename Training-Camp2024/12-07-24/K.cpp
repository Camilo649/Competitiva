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
#define el '\n'
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
    
        string s;
        int n;
        cin >> n >> s;
        int q = 0;
        forn(i, n){
            if(s[i] == '+')
                ++q;
            else if(q){
                --q;
            }
        }
        cout << q << el;
    return 0;
}