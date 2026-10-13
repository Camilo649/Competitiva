#include <bits/stdc++.h>

#define forr(i,a,b) for(int  i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n; cin>>n;
    string words[n];

    forn(i,n){
        cin>>words[i];
    }

    set<char> ltr;

    forn(i,5){
        ltr.insert(words[0][i]);
    }

    int G; cin>>G;
    string States[G];

    forn(i,G){
        cin>>States[i];
    }

    map<string,int> cantState;

    forn(i,n){
        string state = "";

        forn(j,5){
            if(words[i][j]== words[0][j]) state+='*';
            else if(ltr.count(words[i][j])>0) state+='!';
            else state += 'X';
        }
        cantState[state]++;
    }



    forn(i,G){
        cout<<cantState[States[i]]<<nl;
    }

    
    



    return 0;
}