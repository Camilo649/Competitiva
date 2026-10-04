#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 2<<17; // > 2e5

using namespace std;

// Debugging
#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    if (DBG) os << "[";
    for (auto& x : v) os << x << (DBG ? ", " : " ");
    return DBG ? os << "]" : os;
}

template<typename S, typename T> ostream& operator<<(ostream& os, const pair<S, T>& p) {
    return os << (DBG ? "(" : "") << p.fst << (DBG ? ", " : " ") << p.snd << (DBG ? ")" : "");
}

// ======================================================================
// 1. ZONA MATEMÁTICA (Acá configuras la lógica de tu problema)
// ======================================================================

const int NO_OPERATION  = -1;
const int SET_FULL      = -2;
const int SET_EMPTY     = -3;

// ¿Qué guarda cada nodo del árbol?
struct Node {
    ll val = 0;
    ll cap = 0;
};

// ¿Qué guarda el post-it (lazy)?
struct LazyTag {
    ll assign = NO_OPERATION;
};

// A) Fusión de nodos (Push-up) - IMPORTANTE EL ORDEN: izq luego der
Node compose(Node izq, Node der) {
    Node res;
    res.val = izq.val + der.val; 
    res.cap = izq.cap + der.cap;
    return res;
}

// B) Aplicar el post-it al nodo
Node apply_lazy(Node nodo, LazyTag tag, int tl, int tr) {
    if (tag.assign == NO_OPERATION) return nodo;
    if (tag.assign == SET_EMPTY) nodo.val = 0;
    else if (tag.assign == SET_FULL) nodo.val = nodo.cap;
    else nodo.val = tag.assign;
    return nodo;
}

// C) Componer post-its (Cronología: 'viejo' ya estaba, 'nuevo' va llegando)
LazyTag compose_lazy(LazyTag viejo, LazyTag nuevo) {
    if (nuevo.assign == NO_OPERATION) return viejo;
    if (viejo.assign == NO_OPERATION) return nuevo;    
    LazyTag res;
    res.assign = nuevo.assign;
    return res;
}

// ======================================================================
// 2. ZONA DEL SEGMENT TREE (Lógica de recorrido - Intocable)
// ======================================================================

int n;
Node t[2*MAXN];
LazyTag lazy[2*MAXN];

void buildst(int a[]) {
    forn(i,n) t[n+i] = {0,a[i]};
    for (int i = n-1; i > 0; i--)
        t[i] = compose(t[2*i], t[2*i+1]);
}

// Propagar el post-it a los hijos
void propagate(int k, int tl, int tr) {
    if (lazy[k].assign == NO_OPERATION) return;
    
    int mid = (tl+tr)/2;

    // 1. Aplicamos el efecto del lazy a los valores reales de los hijos
    t[2*k] = apply_lazy(t[2*k], lazy[k], tl, mid);
    t[2*k+1] = apply_lazy(t[2*k+1], lazy[k], mid+1, tr);
    
    // 2. Acumulamos el post-it en el historial de los hijos
    lazy[2*k] = compose_lazy(lazy[2*k], lazy[k]);
    lazy[2*k+1] = compose_lazy(lazy[2*k+1], lazy[k]);
    
    // 3. Rompemos el post-it del padre
    lazy[k] = LazyTag(); 
}

void updateRange(int k, int tl, int tr, int l, int r, LazyTag upd) {
    if (l > tr || r < tl) return; // Fuera de rango
    
    if (tl >= l && tr <= r) { // Adentro del rango: aplicamos y cortamos
        t[k] = apply_lazy(t[k], upd, tl, tr);
        lazy[k] = compose_lazy(lazy[k], upd);
        return;
    }
    
    propagate(k, tl, tr); // Propagamos antes de bajar
    
    int mid = (tl+tr)/2;
    updateRange(2*k, tl, mid, l, r, upd);
    updateRange(2*k+1, mid+1, tr, l, r, upd);
    
    t[k] = compose(t[2*k], t[2*k+1]); // Actualizamos el padre al subir
}

Node query_sum(int k, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) return Node(); // Nodo neutro
    
    if (tl >= l && tr <= r) return t[k]; // Adentro del rango
    
    propagate(k, tl, tr); // Propagamos antes de bajar
    
    int mid = (tl+tr)/2;
    return compose(
        query_sum(2*k, tl, mid, l, r),
        query_sum(2*k+1, mid+1, tr, l, r)
    );
}

int walk(int k, int tl, int tr, int b, int v) // Devuelve el indice en el arreglo del barril que se llena parcialmente
{
    if(tl == tr) return tr;

    propagate(k, tl, tr);

    int mid = (tl+tr)/2;

    if(b > tr) 
    {
        ll aval = t[2*k+1].cap - t[2*k+1].val;
        if(v<=aval) return walk(2*k+1, mid+1, tr, b, v);
        else  return walk(2*k, tl, mid, b, v-aval);
    }

    if(b <= mid) return walk(2*k, tl, mid, b, v);
    else {
        Node aux = query_sum(1,0,n-1,mid+1,b);
        ll aval = aux.cap - aux.val;
        if(v<=aval) return walk(2*k+1, mid+1, tr, b, v);
        else  return walk(2*k, tl, mid, b, v-aval);
    }
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m; cin >> n >> m;
    int size = 1; while(size<n) size<<=1;
    int a[size] = {}; forn(i,n) cin >> a[i];
    n = size;

    buildst(a);

    forn(j,m)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int b,v; cin >> b >> v;
            Node aux = query_sum(1,0,n-1,0,b-1);
            ll d = aux.cap - aux.val;
            if(v>=d) updateRange(1,0,n-1,0,b-1,{SET_FULL});
            else 
            {
                int k = walk(1,0,n-1,b-1,v);
                //print(k); print(b-1);
                aux = query_sum(1,0,n-1,k+1,b-1);
                d = aux.cap - aux.val;
                updateRange(1,0,n-1,k+1,b-1,{SET_FULL});
                ll new_val = (ll)v - d + query_sum(1,0,n-1,k,k).val;
                //print(new_val);
                updateRange(1,0,n-1,k,k,{new_val});
            }
        }
        else
        {
            int l,r; cin >> l >> r;
            cout << query_sum(1,0,n-1,l-1,r-1).val << nl;
            updateRange(1,0,n-1,l-1,r-1,{SET_EMPTY});
        }
    }
    
    return 0;
}