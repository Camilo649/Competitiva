#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<tuple<int,int,int>> edges; // u,v,w

bool isTree(vector<int>& idxs)
{
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    function<int(int)> find = [&](int x){ return parent[x]==x ? x : parent[x]=find(parent[x]); };

    for (int idx : idxs)
    {
        auto [u,v,w] = edges[idx];
        int a = find(u), b = find(v);
        if (a == b) return false; // ciclo
        parent[a] = b;
    }
    // chequear conexo: un solo componente
    int root = find(0);
    for (int i = 1; i < n; i++) if (find(i) != root) return false;
    return true;
}

int main()
{
    cin >> n >> m >> k;
    edges.resize(m);
    for (auto& [u,v,w] : edges) { cin >> u >> v >> w; u--; v--; }

    vector<int> all(m);
    iota(all.begin(), all.end(), 0);

    int best = INT_MAX;
    vector<int> comb(n-1);
    // generar todas las combinaciones de n-1 indices de m
    function<void(int,int)> gen = [&](int start, int count)
    {
        if (count == n-1)
        {
            if (isTree(comb))
            {
                int mx = 0;
                long long cost = 0;
                for (int idx : comb) mx = max(mx, get<2>(edges[idx]));
                
                if (mx <= k)
                {
                    // hay que subir la maxima hasta k (las demas ya estan bien, quedan <=k)
                    cost = k - mx;
                }
                else
                {
                    // hay que bajar TODAS las que superen k, hasta k
                    for (int idx : comb)
                    {
                        int w = get<2>(edges[idx]);
                        if (w > k) cost += w - k;
                    }
                }
                best = min(best, (int)cost);
            }
            return;
        }
        for (int i = start; i < m; i++)
        {
            comb[count] = i;
            gen(i+1, count+1);
        }
    };
    gen(0, 0);

    cout << best << "\n";
    return 0;
}