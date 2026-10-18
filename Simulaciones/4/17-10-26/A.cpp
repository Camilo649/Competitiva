#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    string S; cin>>S;

    reverse(ALL(S));

    set<char> ltr;

    forn(i,SZ(S)){
        if(ltr.count(S[i])>0){
            cout<<SZ(S)-i<<nl;
            break;
        }
        ltr.insert(S[i]);
    }

    return 0;
}