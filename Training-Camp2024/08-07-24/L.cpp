#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; ++i)
#define ll long long
#define vi vector<int>
#define rec(i, a, b) for(int i=a; i<b; ++i)
#define revn(i, n) for(int i=n-1; i>=0; --i)
//#define b(d) d.begin()
//#define e(d) d.end()
#define range(d) b(d), e(d)
#define pa printf("a\n")
#define sz(d) d.size()
#define f first
#define s second
#define printd(d) for(auto e : d) cout << e << ' '; cout << '\n';
#define pii pair<int, int>
#define MAXS 200010
//#define MAT

using namespace std;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;
    bitset<MAXS> vst;
    vector<pii> e(m);
    vi v[MAXS], d(n);
    forn(i, m){
        cin >> e[i].f >> e[i].s;
        v[e[i].f].push_back(e[i].s);
        v[e[i].s].push_back(e[i].f);
    }
    //bfs direccional
    queue<int>q;
    q.push(e[0].f);
    d[e[0].f] = 1; // 1 => apunta a otro, 2 => es apuntado 
    bool f = true;
    while(!q.empty() && f){
        int n = q.front();
        q.pop();
        if(vst[n]) continue;
        vst[n] = 1;
        for(auto e: v[n]){
            if(d[n] == d[e]){

                cout << "NO\n";
                return 0;
            }
            else if(d[n] == 1) d[e] = 2;
            else d[e] = 1;
            q.push(e);
        }
    }
    cout << "YES\n";
    for(auto x: e){
        if(d[x.f] == 1) cout << 1;
        else cout << 0;
    }
    cout << '\n';
    
    
    return 0;
}


