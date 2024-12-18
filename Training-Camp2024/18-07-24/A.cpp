#include<bits/stdc++.h>
 
// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
// redefiniciones
typedef long long ll;
typedef long double ld;
 
using u64 = uint64_t;
 
const int MAXN = -1;
 
using namespace std;
 
int t;
 
int main()
{
    
    cin >> t;
    
    while (t--){
        bool flag = false;
        int n;
        cin >> n;
        vector<int> v(n), u(n+1);
        forn(i,n) {
            cin >> v[i];
        }
        for(int i=n-1;i>=0;--i){
            while(v[i]>n){
                v[i]/=2;
            }   
        }
        sort(v.begin(), v.end());
        for(int i=n-1; i>=0; --i){
            if(!u[v[i]]) u[v[i]]=1;
            else{
                while(v[i]){
                    v[i]/=2;
                    if(!u[v[i]]){
                        u[v[i]]=1;
                        break;
                    }
                }
                if(!v[i]){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}