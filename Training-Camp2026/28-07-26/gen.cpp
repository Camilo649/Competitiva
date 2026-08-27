#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    srand(atoi(argv[1]));

    int n = rand() % 4 + 2; // 2..5
    // generar un arbol para garantizar conexidad, despues agregar aristas extra
    vector<pair<int,int>> allEdges;
    for (int i = 1; i < n; i++)
    {
        int p = rand() % i;
        allEdges.push_back({p, i});
    }
    // agregar algunas aristas extra (sin duplicar)
    set<pair<int,int>> used;
    for (auto [a,b] : allEdges) used.insert({min(a,b), max(a,b)});

    int extra = rand() % 3;
    for (int t = 0; t < extra; t++)
    {
        int a = rand()%n, b = rand()%n;
        if (a==b) continue;
        if (used.count({min(a,b),max(a,b)})) continue;
        used.insert({min(a,b),max(a,b)});
        allEdges.push_back({a,b});
    }

    int m = allEdges.size();
    int k = rand() % 10 + 1;

    cout << n << " " << m << " " << k << "\n";
    for (auto [a,b] : allEdges)
    {
        int w = rand() % 10 + 1;
        cout << a+1 << " " << b+1 << " " << w << "\n";
    }
    return 0;
}