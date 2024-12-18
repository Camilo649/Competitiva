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
    
    int n;
    ll sum=0;
    cin >> n;
    vector<int>v(n);
    forn(i, n){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    forn(i, n){
        sum+=v[i];
    }
    ll sum2 = sum;
    forn(i, v.size()-1){
        sum2 += sum; 
        sum -= v[i];
    }
    cout << sum2 << "\n";
    return 0;
}
