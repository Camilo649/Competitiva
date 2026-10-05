#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second 
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

using namespace std;

bool has_solution = false;

vector<vector<bool>> visited;
vector<vector<bool>> maze1;

int R, C;

void dfs(int i, int j){
    if (visited[i][j] || maze1[i][j])
        return;

    visited[i][j] = true;

    if (i == R-1){
        has_solution = true;
        return;
    }


    //cout<<i<<" "<< R <<nl;
    dfs(i+1, j);
    dfs(i, (j+1) % C);
    dfs(i, (j+C-1) % C);
    if (i > 0) dfs(i-1, j);
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R;
    cin >> C;

    string s; cin >> s;
    auto bolt = vector<bool>(C);
    forn(j, C){
        bolt[j] = s[j] == '1';
    }

    auto maze = vector<vector<bool>>(R, vector<bool>(C));
    forn(i, R){
        string row; cin >> row;
        forn(j, C){
            maze[i][j] = row[j] == '1';
        }
    }


    forn(orientation, 2) {

        maze1   = vector<vector<bool>>(R, vector<bool>(C, false));
        visited = vector<vector<bool>>(R, vector<bool>(C, false));

        forn(i, R){
            forn(j, C){
                forn(k, C){
                    if (maze[i][k] && bolt[(j+k)%C]){
                        maze1[i][j] = true;
                        break;
                    }
                }
            }
        }

        forn(j, C){
            dfs(0, j);
            if (has_solution){
                cout << 'Y' << nl;
                return 0;
            }
        }

        reverse(ALL(bolt));

    }

    cout << 'N' << nl;

    return 0;
}