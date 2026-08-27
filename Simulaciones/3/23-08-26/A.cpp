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
#define nl '\n';
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

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

char winner(string board)
{
    if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X') return 'X';
    else if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X') return 'X';
    else if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X') return 'X';
    else if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X') return 'X';
    else if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X') return 'X';
    else if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') return 'X';
    else if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') return 'X';
    else if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') return 'X';
    else if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O') return 'O';
    else if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O') return 'O';
    else if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O') return 'O';
    else if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O') return 'O';
    else if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O') return 'O';
    else if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O') return 'O';
    else if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O') return 'O';
    else if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O') return 'O';
    else return 'E';
}

map<int,set<int>> restrics;

map<int,set<int>> remove(int num, map<int,set<int>> restrics)
{
    forn(i,9) restrics[i].erase(num);
    return restrics;
}

string set_string(string s, int i, char c)
{
    s[i] = c;
    return s;
}

char solve (int turn, map<int,set<int>> restrics, string board)
{
    char w = winner(board);
    if (w != 'E') return w;

    char best = (turn%2==0) ? 'O' : 'X';
    bool jugoAlguna = false;

    forn(i,9)
    {
        if(board[i] == '.' && restrics[i].empty())
        {
            jugoAlguna = true;
            char resultado = solve(turn+1, remove(i, restrics), set_string(board, i, (turn%2==0 ? 'X' : 'O')));
            if(turn%2 == 0 && ((resultado == 'X' && best != 'X') || (resultado == 'E' && best == 'O'))) best = resultado;
            if(turn%2 == 1 && ((resultado == 'O' && best != 'O') || (resultado == 'E' && best == 'X'))) best = resultado;
        }
    }

    if (!jugoAlguna) return 'E';

    // print(turn);
    // print(board);
    // print(best);

    return best;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    forn(i,n)
    {
        int a,b; cin >> a >> b; a--; b--;
        restrics[b].insert(a);
    }

    char w = solve(0, restrics, ".........");
    print(w);
    
    return 0;
}