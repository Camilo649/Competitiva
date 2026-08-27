
#include <bits/stdc++.h>

using namespace std;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
//#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
//#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
//#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
#define forn(i, n) for(ll i=0; i<n; i++);
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
//template < typename T = int > using Pair = pair < T, T >;
//vector < string > RET = {"NO", "YES"};



/*


n
g
b





cuantos dias para la primera mitad?

cuando llego, ya pude pintar la siguiente mitad?
si ya pude es eso
si no quizas solo hay que seguir pintando lo que falta

chunk = g + b


10
3

3


*/



int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    //cout << "Hi" << '\n';
    ll test_cases = 1;
    cin >> test_cases;

    ll n;
    ll g;
    ll b;

    vector<ll> ns;
    vector<ll> gs;
    vector<ll> bs;


    for (ll test_i=0; test_i < test_cases; test_i++){
        cin >> n;
        cin >> g;
        cin >> b;
        ns.pb(n);
        gs.pb(g);
        bs.pb(b);
    }

    for(int tc = 0; tc < test_cases; tc++){
        n = ns[tc];
        g = gs[tc];
        b = bs[tc];

        ll chunk = g+b;
        ll minimum = (n/2) + (n % 2);

        ll m;
        //ll rest;
        if (minimum % g != 0){
            m = chunk * (minimum / g) + minimum % g;
            //rest = ((n/2) / g) * b;
        }
        else {
            m = chunk * ((minimum / g)-1) + g;
            //rest = b * chunk * (((n/2) / g)-1)
        }



        //cout << "chunk" << chunk <<"; m" << m << "rest" << rest << endl;

        if (m >= n){
            cout << m << endl;
        }
        else {
            cout << n << endl;
        }


        /*
        if (rest + n/2 >= n){
            cout << m << endl;
        }
        else {
            cout << n << endl;
        }
        */

    }
    return 0;
}


