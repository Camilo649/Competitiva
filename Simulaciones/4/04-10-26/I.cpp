#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
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

const int MAXN = 101;

using namespace std;


int C,R;

int matriz[MAXN][MAXN] = {};
pair<int, int> posmat [MAXN*MAXN];

bitset<MAXN*MAXN> visitedgeneral = {};

int dfs(int r){

    visitedgeneral[r] = 1;
    bitset<MAXN*MAXN> visited;
    visited[r] = 1;

    int ans = 0;
    priority_queue<int> nodos;

    nodos.push(-r);

    while(!nodos.empty()){

        int y = posmat[-nodos.top()].first;
        int x = posmat[-nodos.top()].second;

        nodos.pop();
        ans++;

        
        visitedgeneral[matriz[y][x]] = 1;

        if(x>0 && !visited[matriz[y][x-1]] && matriz[y][x-1]>matriz[y][x]){
            visited[matriz[y][x-1]] = 1;
            nodos.push(-matriz[y][x-1]);
        }

        if(x<R-1 && !visited[matriz[y][x+1]] && matriz[y][x+1]>matriz[y][x]){
            visited[matriz[y][x+1]] = 1;
            nodos.push(-matriz[y][x+1]);
        }
        
        if(y>0 && !visited[matriz[y-1][x]] && matriz[y-1][x]>matriz[y][x]){
            visited[matriz[y-1][x]] = 1;
            nodos.push(-matriz[y-1][x]);
        }
        if(y<C-1 && !visited[matriz[y+1][x]] && matriz[y+1][x]>matriz[y][x]){
            visited[matriz[y+1][x]] = 1;
            nodos.push(-matriz[y+1][x]);
        }
        
    }
    return ans;
}


int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>C>>R;

    forn(i,C){
        forn(j,R){
            cin>>matriz[i][j];
            posmat[matriz[i][j]] = {i,j};
        }
    }


    int ans = 0;

    forn(i,R*C){
        if(!visitedgeneral[i+1]) ans = max(ans, dfs(i+1));
    }
    

    //cout<<nl;
    cout<<ans<<nl;

    return 0;
}