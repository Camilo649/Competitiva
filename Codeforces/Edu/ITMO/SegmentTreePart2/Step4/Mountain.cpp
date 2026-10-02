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

const ll NO_OPERATION  = -2e9;


// ¿Qué guarda cada nodo del árbol?
struct Node {
    ll a;
    ll b;
    ll last_h = 0;
    ll mx = 0;
};

// ¿Qué guarda el post-it (lazy)?
struct LazyTag {
    ll assign = NO_OPERATION;
};

struct Query
{
    char op;
    ll a;
    ll b;
    ll D;
    ll h;
};


// A) Fusión de nodos (Push-up) - IMPORTANTE EL ORDEN: izq luego der
Node compose(Node izq, Node der) {
    Node res;
    res.a = izq.a;
    res.b = (der.b == 2e9 ? izq.b : der.b);
    res.last_h = izq.last_h+der.last_h;
    res.mx = max(izq.mx, izq.last_h + der.mx);
    return res;
}

// B) Aplicar el post-it al nodo
Node apply_lazy(Node nodo, LazyTag tag) {
    if (tag.assign == NO_OPERATION || nodo.a == 2e9) return nodo;
    nodo.last_h = tag.assign * (nodo.b-nodo.a+1);
    nodo.mx = max(0LL,nodo.last_h);
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

int n,N;
Node t[2*MAXN];
LazyTag lazy[2*MAXN];

// Propagar el post-it a los hijos
void propagate(int k) {
    if (lazy[k].assign == NO_OPERATION) return;
    
    // 1. Aplicamos el efecto del lazy a los valores reales de los hijos
    t[2*k] = apply_lazy(t[2*k], lazy[k]);
    t[2*k+1] = apply_lazy(t[2*k+1], lazy[k]);
    
    // 2. Acumulamos el post-it en el historial de los hijos
    lazy[2*k] = compose_lazy(lazy[2*k], lazy[k]);
    lazy[2*k+1] = compose_lazy(lazy[2*k+1], lazy[k]);
    
    // 3. Rompemos el post-it del padre
    lazy[k] = LazyTag(); 
}

void updateRange(int k, int l, int r, LazyTag upd) {
    if (l > t[k].b || r < t[k].a) return; // Fuera de rango
    
    if (t[k].a >= l && t[k].b <= r) { // Adentro del rango: aplicamos y cortamos
        t[k] = apply_lazy(t[k], upd);
        lazy[k] = compose_lazy(lazy[k], upd);
        return;
    }
    
    propagate(k); // Propagamos antes de bajar
    
    updateRange(2*k, l, r, upd);
    updateRange(2*k+1, l, r, upd);
    
    t[k] = compose(t[2*k], t[2*k+1]); // Actualizamos el padre al subir
}

ll query(ll h) {
    if(t[1].mx <= h) return n;
    int i = 1;
    while(i<N)
    {
        propagate(i); // Propagamos antes de bajar
        if(t[2*i].mx <= h) {h-=t[2*i].last_h; i<<=1; i++;} // Me muevo al hijo derecho
        else i<<=1;                                        // Me muevo al hijo izquierdo 
    }

    ll size = (t[i].b-t[i].a+1);
    ll D = t[i].last_h/size;
    //if(D<=0) return t[i].b;
    return (t[i].a-1) + h/D;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    queue<Query> q;
    set<ll> s;
    s.insert(1);
    s.insert(n + 1);
    char c; cin >> c;
    while(c != 'E')
    {
        Query que;
        que.op = c;
        if(c == 'I')
        {
            ll a,b,D; cin >> a >> b >> D;
            que.a = a; que.b = b; que.D = D;
            s.insert(a); s.insert(b+1);
        }
        else
        {
            ll h; cin >> h;
            que.h = h;
        }
        q.push(que);
        cin >> c;
    }

    N = SZ(s)-1;
    int size=1; while(size<N) size<<=1;
    N = size;
    int i = 0;
    ll last = -1;
    for(auto range : s) {
        if (last != -1) {
            t[i + N].a = last;
            t[i + N].b = range - 1;
            i++;
        }
        last = range;
    }
    forr(i,SZ(s)-1,N)
    {
        t[i + N].a = 2e9;
        t[i + N].b = 2e9;
    }
    for (int i = N-1; i > 0; i--)
        t[i] = compose(t[2*i], t[2*i+1]);
    
    while(!q.empty())
    {
        Query que = q.front(); q.pop();
        if(que.op == 'I')
        {
            updateRange(1,que.a, que.b,{que.D});
        }
        else
        {
            cout << query(que.h) << nl;
        }
    }
    
    return 0;
}