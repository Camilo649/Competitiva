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
#define f first
#define s second
#define printd(d) for(auto e : d) cout << e << ' '; cout << '\n';
#define pii pair<int, int>
#define nl cout << "\n";
#define ws << " " <<
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
    
    int n, k;
    cin>>n>>k;
    n+=2;
    vi v(n);
    v[0]=0;
    v[n-1]=k;
    int ans=0;
    //Hasta aca como habiamos visto
    forn(i, n-2){
        cin >> v[i+1];
    }
        
    //Creo dos arreglos a guarda la suma prefija de los minutos que paso prendida la lampara
    //b guarda lo mismo pero para los periodos apagados
    vi a = {0}, b = {0};
    rec(i, 1, n){
        if(i%2)
            a.push_back(v[i]-v[i-1]+a.back());
        else b.push_back(v[i]-v[i-1]+b.back());
    }
        
    //El minimo caso es que no se agregue ningun numero y la suma de los periodos
    //prendidos sea respuesta
    int mx=a.back();
    
    //si puedo meter el 1 despues del 0 en el arreglo lo calculo
    if(n>3 && v[1]!=1)max(mx, 1+b.back());
    
    //i ficticio es un indice para probar v[i]+1 y v[i]-1, el primero estaria
    //en i+1 y el segundo en i
    int ifict=1;
    int j=0;
    rec(i,1,n){    
        int pr=v[i]-1;
        if(pr != v[i-1]){
            //pruebo si poniendo v[i]-1 maximizo
            mx = max(mx, a[ifict/2]+abs(pr-v[j])+(b.back()-b[ifict/2]));
        }
        if(ifict%2) j+=2;//dificil de explicar
        ++ifict;
        //al pasar del v[i]-1 al v[i]+1 aumenta el ificticio
        if(ifict==n)break;//termina para no crear un numero imposible
        pr=v[i]+1;
        if(pr==v[i+1]) continue;
        //pruebo si poniendo v[i]+1 maximizo
        mx = max(mx, a[ifict/2]+abs(pr-v[j])+(b.back()-b[ifict/2]));
    }
    cout << mx << endl;
    return 0;
}


