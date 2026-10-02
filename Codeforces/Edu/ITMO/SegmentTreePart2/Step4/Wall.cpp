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

const int MAXN = 1<<21; // > 2e6
const ll  INF  = 1e18;

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

// const ll NO_OPERATION  = -1;

// ¿Qué guarda cada nodo del árbol?
struct Node {
    ll mn = 0;
    ll mx = 0;
};

// ¿Qué guarda el post-it (lazy)?
struct LazyTag {
    ll L;
    ll R;
};

// A) Fusión de nodos (Push-up) - IMPORTANTE EL ORDEN: izq luego der
Node compose(Node izq, Node der) {
    Node res;
    res.mn = min(izq.mn,der.mn);
    res.mx = max(izq.mx,der.mx);
    return res;
}

// B) Aplicar el post-it al nodo
Node apply_lazy(Node nodo, LazyTag tag, int tl, int tr) {
    nodo.mn = min(tag.R, max(tag.L, nodo.mn));
    nodo.mx = min(tag.R, max(tag.L, nodo.mx));
    return nodo;
}

// C) Componer post-its (Cronología: 'viejo' ya estaba, 'nuevo' va llegando)
LazyTag compose_lazy(LazyTag viejo, LazyTag nuevo) {   
    LazyTag res;
    res.L = min(nuevo.R, max(nuevo.L, viejo.L));
    res.R = min(nuevo.R, max(nuevo.L, viejo.R));
    return res;
}

// ======================================================================
// 2. ZONA DEL SEGMENT TREE (Lógica de recorrido - Intocable)
// ======================================================================

Node t[2*MAXN];
LazyTag lazy[2*MAXN];

// Propagar el post-it a los hijos
void propagate(int k, int tl, int tr) {
    if (lazy[k].L == 0 && lazy[k].R == INF) return;
    
    int mid = (tl+tr)/2;
    
    // 1. Aplicamos el efecto del lazy a los valores reales de los hijos
    t[2*k] = apply_lazy(t[2*k], lazy[k], tl, mid);
    t[2*k+1] = apply_lazy(t[2*k+1], lazy[k], mid+1, tr);
    
    // 2. Acumulamos el post-it en el historial de los hijos
    lazy[2*k] = compose_lazy(lazy[2*k], lazy[k]);
    lazy[2*k+1] = compose_lazy(lazy[2*k+1], lazy[k]);
    
    // 3. Rompemos el post-it del padre
    lazy[k] = {0,INF}; 
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

Node query(int k, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) return Node(); // Nodo neutro
    
    if (tl >= l && tr <= r) return t[k]; // Adentro del rango
    
    propagate(k, tl, tr); // Propagamos antes de bajar
    
    int mid = (tl+tr)/2;
    return compose(
        query(2*k, tl, mid, l, r),
        query(2*k+1, mid+1, tr, l, r)
    );
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    forn(i, 2*MAXN) {
        lazy[i].L = 0;
        lazy[i].R = INF;
    }

    int n,k; cin >> n >> k;
    int N = n;
    int size=1; while(size<n) size<<=1;
    n = size;

    forn(j,k)
    {
        int op; cin >> op;
        int l,r,h; cin >> l >> r >> h;
        LazyTag upd;
        if(op == 1) upd = {h,INF};
        else upd = {0,h};
        updateRange(1,0,n-1,l,r,upd);
    }

    forn(i,N)
    {
        cout << query(1,0,n-1,i,i).mx << nl;
    }
    
    return 0;
}