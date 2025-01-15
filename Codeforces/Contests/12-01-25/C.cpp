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

const int MAXN = -1;

using namespace std;
 
int t;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        string S; cin >> S;
        vector<vector<ll>> A;
        for (int i = 0; i < N; i++) {
            A.push_back(vector<ll>(M));
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        int x = 0, y = 0;
        for (char c : S) {
            if (c == 'D') {
                long long su = 0;
                for (int i = 0; i < M; i++) {
                    su += A[x][i];
                }
                A[x][y] = -su;
                ++x;
            } else {
                long long su = 0;
                for (int i = 0; i < N; i++) {
                    su += A[i][y];
                }
                A[x][y] = -su;
                ++y;
            }
        }
        long long su = 0;
        for (int i = 0; i < M; i++) {
            su += A[N-1][i];
        }
        A[N-1][M-1] = -su;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

    }
    return 0;
}