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
#define f first
#define s second
#define printd(d) for(auto e : d) cout << e << ' '; cout << '\n';
#define pii pair<int, int>
#define nl cout << "\n"
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
        string s;
        cin >> s;
        //busco max subsecuencia de l seguidas
        int l = 0;
        forn(i, s.size()){
            int aux = 0;
            while(i<s.size() && s[i] == 'L'){
                ++aux;++i;
            }
            l = max(aux, l);
        }
        cout << l+1;nl;
    }
    return 0;
}


