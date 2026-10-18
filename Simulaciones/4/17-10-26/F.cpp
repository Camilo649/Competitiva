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


    int K,N; cin>>K>>N;

    if((N/3) == K && N%3 == 0){
        forn(i, N){
            if(i%3==1){cout<<'X';}
            else{cout<<'-';}
        }
        cout<<nl;
    }
    else if((N/3)+1 == K && N%3 == 0){
        forn(i, N-1){
            if(i%3==0){cout<<'X';}
            else{cout<<'-';}
        }
        cout<<'X';
        cout<<nl;
    }
    else if((N/3)+1 == K && N%3 != 0){

        forn(i, N-(N%3)){
            if(i%3==0){cout<<'X';}
            else{cout<<'-';}
        }

        if(N%3 == 1) cout<<'X';
        else if(N%3 == 2) cout<<"X-";
        cout<<nl;
    }else if((N+1)/2 == K){
        forn(i, N){
            if(i%2==1){cout<<'-';}
            else{cout<<'X';}
        }
        cout<<nl;
    }else{
        cout<<"*"<<nl;
    }

    return 0;
}