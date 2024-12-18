#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; ++i)
#define rev(i, n) for(int i=n-1; i>=0; --i)
#define ll long long
#define vi vector<int>
//#define MAT
using namespace std;
#define MAXD 550
 
int main()
{
    #ifdef MAT
        freopen("input.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    ll n, m;
    ll mz[MAXD][MAXD];
    cin >> n >> m;
    forn(i, n){
        forn(j, m){
            cin >> mz[i][j];
        }
    }
    for(int i=n-2; i>0; --i){
        for(int j=m-2; j>0; --j){
            if(mz[i][j] == 0){
                mz[i][j] = min(mz[i+1][j], mz[i][j+1]) - 1;
            }
        }
    }
    ll sum = 0;
    forn(i, n){
        forn(j, m){
            sum+=mz[i][j];
        }
    }
    bool flag = true;
    for(int i=0; i<n && flag; ++i){
        for(int j=0; j<m-1 && flag; ++j){
            if(mz[i][j] >= mz[i][j+1]) flag = false;
        }
    }
    for(int i=0; i<n-1 && flag; ++i){
        for(int j=0; j<m && flag; ++j){
            if(mz[i][j] >= mz[i+1][j]) flag = false;
        }
    }
    if(!flag){
        cout << "-1\n";
        return 0;
    }
    cout << sum << '\n';   
    
    return 0;
}