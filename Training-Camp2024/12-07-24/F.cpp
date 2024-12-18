#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; ++i)
#define ll long long
#define vi vector<int>
#define rec(i, a, b) for(int i=a; i<b; ++i)
#define revn(i, n) for(int i=n-1; i>=0; --i)
#define bg(d) d.begin()
#define ed(d) d.end()
#define range(d) bg(d), ed(d)
#define sz(d) d.size()
#define f first
#define s second
#define printd(d) for(auto e : d) cout << e << ' '; cout << '\n';
#define pii pair<int, int>
#define nl cout<<"\n"
#define ws cout<<" "
#define MAT
using namespace std;

int main()
{
    #ifdef MAT
        freopen("input.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m, k;cin>>n>>m>>k;
    if(k==1){
        cout << n*(n-1)/2-m;nl;
        return 0;
    }
    
    vi nc(n+1);  //a q nacion pertenece c/nodo
    vi sb(n+1);   //subditos de c/gobierno
    vi G(k);
    forn(i, k){
        cin >> G[i];
        nc[G[i]]=-1;
    }
    vector<vi> gr(n+1);    //grafo perse
    forn(i,m){
        int x, y;
        cin >> x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    bitset<10000000>vst;
    int mx=G[0], j=0;
    for(int g: G){
        //bfs
        if(!g)continue;
        queue<int>q;
        q.push(g);
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(vst[x])continue;
            vst[x]=1;
            sb[g]++;    //el gobierno tiene un nodo mas como subdito
            nc[x]=g;    //el nodo x pertenece al gobierno g
            for(int y: gr[x])
                q.push(y);
        }
        if(mx<sb[g]){
            mx = sb[g];
            j=g;
        }
    }
    int free=0;
    rec(i,1,n+1){  //cuento cuantos nodos libres tengo para darselos al gobierno con mas ciudades
//        cout << nc[i];ws;
        if(!(nc[i])) free++;
    }
    sb[j] += free;
    ll sum=0;
    forn(i, n+1){
//        cout << sb[i];ws;
        sum+=(sb[i]*(sb[i]-1))/2;
    }
    sum-=m;
    cout << sum;nl;
    
    return 0;
}


