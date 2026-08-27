#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), e.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;


    cin>>S;

    int n = SZ(S);
    int arr[3] = {};
    
    forn(i,n){
        if(S[i]=='A' or S[i] == 'U') arr[0]++;
        if(S[i]=='T') arr[1]++;
        if(S[i]=='P') arr[2]++;
    }

    int ans = min(arr[0], min(arr[1],arr[2]));
    cout<< ans;
    return 0;
}