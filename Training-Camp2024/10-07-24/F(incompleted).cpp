#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)
#define ll long long
#define vi vector<int>
#define MAT
using namespace std;

ll gaussum(int n){
    return (n*(n+1))/2;
}

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    forn(i, n)
        cin >> v[i];
    multiset<int>q;
    forn(i, n){
        int x=0;
        while(v[i]){
            ++x;++i;
        }
        q.insert(x);
    }
    int ans = 0;
    bool flag = true;
    while(flag){
        ll p=0;
        for(auto e:q)
            p += gaussum(e);
        if(p>=k){
            int a = *(q.rbegin());
            if(a>2){
                ans+=2;
                int b = a/3;
                q.insert(b);
                q.insert(b);
                q.insert(a-2*b);
            }
            else{
                ans += 1;
                q.insert(1);
            }
        }
        else{
            cout << ans << '\n';
        }
    }
    return 0;
}


