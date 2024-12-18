#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; ++i)
#define ll long long
#define vi vector<int>
#define rec(i, a, b) for(int i=a; i<b; ++i)
#define revn(i, n) for(int i=n-1; i>=0; --i)
#define b(d) d.begin()
#define e(d) d.end()
#define range(d) b(d), e(d)
#define pa printf("a\n")
#define sz(d) d.size()
#define MAXN 110
#define pii pair<int,int>
//#define MAT
using namespace std;
 
int main()
{
    #ifdef MAT
        freopen("input.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int mx = 0;
    bitset<MAXN>b;
    vector<pair<int, int>>e[MAXN];
    forn(i, m){
        int u, v, c;
        cin >> u >> v >> c;
        e[u].push_back(pii(v, c));
        e[v].push_back(pii(u, c));
    }
    int q;
    cin >> q;
    while(q--){
        int u, v, aux;
        cin >> u >> v;
        int cam = 0;
        for(int c=1; c<=m; ++c){
            bitset<MAXN>vis;
            queue<int>qq;
            bool flag = false;
//            cout << vis<<endl;
//            cout << qq.size()<<endl;
            qq.push(u);
            while(!qq.empty()){
                aux = qq.front();
                qq.pop();
                if(vis[aux]) continue;
                vis[aux] = true;
                for(auto node : e[aux]){
                    if(node.first == v && node.second == c){
                        ++cam;
                        flag = true;
                        break;
                    }
                    if(vis[node.first] || node.second != c) continue;
                    qq.push(node.first);
                }
                if(flag) break;
            }
        }
        cout << cam << '\n';
    }
    
    return 0;
}