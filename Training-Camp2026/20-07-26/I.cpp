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
#define GE
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 12;
const int INF = INT32_MAX;

using namespace std;
 
int toMask(const string& s, int n) {
    int mask = 0;
    forn(j, n) if (s[j] == '1') mask |= (1 << j);
    return mask;
}

int main()
{
    #ifdef GE
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, q; cin >> n >> m >> q;
    int w[n]; forn(i,n) cin >> w[i];
    unordered_map<int, int> cant;// guarda un par (x,y). donde x es el entero de la mascara, y la cantidad que se repite
    forn(i,m)
    {
        string s; cin >> s;//ingresa los strings
        int s_mask = toMask(s, n); //los covierta a emteros
        if(cant.count(s_mask) == 0) cant[s_mask] = 0;// crea a la clave de mas
        cant[s_mask]++;
    }
    pair<int, int> query[q]; // lista de querys
    unordered_set<int> aux;// auxiliar con las mascaras de las querys
    forn(i,q)
    {
        string t; int k; cin >> t >> k; // lee las querys
        int t_mask = toMask(t, n); // los comvierte a mascaras
        query[i] = {t_mask,k}; // guarda el par como mascara,k
        aux.insert(t_mask);// inserta las mascaras sin el k en aux
    }

    int totalW = 0;
    forn(j, n) totalW += w[j]; // cuenta el peso total


    vector<int> sumOnes(1 << n, 0); // precalcula los pesos de los strings viendo los bits que estan prendidos
    forn(M, 1 << n)
    {
        forn(j, n)
        {
            if (M & (1 << j)) sumOnes[M] += w[j];
        }
    }

    unordered_map<int,vector<pair<int,int>>> um; // aca guarda 
    // aux es las querys en enteros
    for (auto it = aux.begin(); it != aux.end(); it++) // aca recorre las querys
    {
        int t = *it; // * con esto accedes al valor del puntero it
        for (auto [key, value] : cant) // descomprime el cant (donde guerda las mascaras y las vece que se repite) 
        {
            int diffMask = key ^ t; // compara los bits de la quety con el string con la puerta xor
            int sum = totalW - sumOnes[diffMask]; // ve el peso ayudandose de sumones, donde precalculo el peso de cada mascara posbile.
            um[t].pb({sum,value}); //agrega en la posicion de la query t, la relacion entre los string y la query
        }
        sort(um[t].begin(), um[t].end());// al finalizar los ordena para despues hace run lower bound
    }

    for (auto [key, value] : um) // aca acumula en las veces repetidas
    {
        int acum = 0;
        forn(i, value.size())
        {
            acum += value[i].snd;
            um[key][i].snd = acum;
        }
    }
    
    forn(i,q)
    {
        int t = query[i].fst; int k = query[i].snd;
        auto it = upper_bound(um[t].begin(), um[t].end(), make_pair(k, INT_MAX));// para cada query haces un lower bound, busqeuda binaria, buscando el k, y imprimo el segundo valor
        if (it == um[t].begin()) {
            // no hay ningún par con fst <= k
            cout << 0 << nl;
        } else {
            --it;// para ir al anterior puntero
            // it apunta al par con mayor fst tal que fst <= k
            // it->snd es el acumulado que buscás
            cout << it->snd << nl;//imprime el segundo valor
        }
    }

    return 0;
}