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
    
    ll k, n, x, t;
    cin >> k;
    while(k--)
    {
        ll sum = 0;
        cin >> n >> x >> t;
        ll p = t/x;
        if(n-p<0){
            sum = ((n*(n-1))/2);
            cout << sum << '\n';
            continue;
        }
        sum += (n-p) * p;
        sum+=((p*(p-1))/2);
        cout << sum << '\n';
    }
    
    
    return 0;
}