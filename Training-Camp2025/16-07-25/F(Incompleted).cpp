#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 2e6 + 8;
const double EPS = 1e-10;

using namespace std;
 
int tests;

bool truth[MAXN]; // truth[cmp[i]] = valor de la variable i en la solución (2SAT)
int nvar; // Número de variables originales
int neg(int x) { return MAXN - 1 - x; } // Retorna la negación de x en el grafo
vector<int> g[MAXN]; // Grafo de implicaciones
int n;
int lw[MAXN]; // Representa el "low-link value" de cada nodo para Tarjan
int idx[MAXN]; // Guarda el índice de descubrimiento en el DFS de Tarjan
int qidx; // Contador de nodos visitados en el DFS de Tarjan
int cmp[MAXN]; // Guarda la componente fuertemente conexa (SCC) a la que pertenece cada nodo
int qcmp; // Contador de SCCs encontradas
stack<int> st; // Pila utilizada por el algoritmo de Tarjan

void tjn(int u) {
    lw[u] = idx[u] = ++qidx; // Asigna índice único y low-link inicial
    st.push(u);
    cmp[u] = -2; // Marcamos como parte del stack

    for (int v : g[u]) { // Recorremos vecinos
        if (!idx[v] || cmp[v] == -2) { // Si no ha sido visitado o está en el stack
            if (!idx[v]) tjn(v);
            lw[u] = min(lw[u], lw[v]); // Actualizamos low-link
        }
    }

    if (lw[u] == idx[u]) { // Si encontramos raíz de una SCC
        int x, l = -1;
        do {
            x = st.top();
            st.pop();
            cmp[x] = qcmp; // Asigna SCC a los nodos
            if (min(x, neg(x)) < nvar) l = x; // Identificamos una variable de la SCC
        } while (x != u);

        if (l != -1) truth[qcmp] = (cmp[neg(l)] < 0); // Determinamos el valor de verdad
        qcmp++; // Pasamos a la siguiente SCC
    }
}

/* Ejecuta Tarjan en todo el grafo */
void scc() {
    memset(idx, 0, sizeof(idx)); // Reseteamos idx
    qidx = 0; // Reiniciamos contador de índices
    memset(cmp, -1, sizeof(cmp)); // Inicializamos SCCs
    qcmp = 0; // Reiniciamos contador de SCCs

    for (int i = 0; i < n; i++) 
        if (!idx[i]) tjn(i); // Ejecutamos Tarjan en cada nodo no visitado
}

/* Construye el grafo de implicaciones */
void addor(int a, int b) {
    g[neg(a)].push_back(b); // ¬a → b
    g[neg(b)].push_back(a); // ¬b → a
}

/* Verificacion de satisfactibilidad */
bool satisf(int _nvar) {
    nvar = _nvar; // Guardamos número de variables originales
    n = MAXN; // Definimos tamaño del grafo

    scc(); // Encontramos SCCs

    for (int i = 0; i < nvar; i++)
        if (cmp[i] == cmp[neg(i)]) return false; // Si x y ¬x están en la misma SCC, es insatisfacible

    return true; // Si no hay conflictos, es satisfacible
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m; cin >> n >> m;
    forn(i,n)
    {
        string s; cin >> s;
        if (s.find("->") != string::npos)
        {
            vector<int> left;
            int i = 0;
            while (s[i] != '-')
            {
                left.pb(s[i]-'0');
                i++;
            }
            i += 2;
            vector<int> right;
            while (i<s.size())
            {
                right.pb(s[i]-'0');
                i++;
            }
            
            forn(i,left.size())
            {
                forn(j,right.size())
                {
                    
                }
            }
        }
        else
        {
            addor(s[1]-'0',s[2]-'0');
        }
        
    }
    
    return 0;
}