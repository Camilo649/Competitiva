#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define nl '\n';
#define GG

typedef long long ll;
using namespace std;

int tests;
const int MAXN = 5000 + 3;
int l[MAXN], r[MAXN], u[MAXN], v[MAXN];
int n;

bool check(int m)
{
    if (m == 0) return true;

    int L = 0, R = n - 1;
    int cntL = 0, cntR = 0;

    while (L <= R && cntL + cntR < m)
    {
        int leftRank = cntL + 1;
        int rightRankIfLeft = m - leftRank + 1;
        bool leftInvalid = (leftRank >= l[L] && leftRank <= r[L]) ||
                            (rightRankIfLeft >= u[L] && rightRankIfLeft <= v[L]);

        if (leftInvalid) { L++; continue; }

        int rightRank = cntR + 1;
        int leftRankIfRight = m - rightRank + 1;
        bool rightInvalid = (rightRank >= u[R] && rightRank <= v[R]) ||
                             (leftRankIfRight >= l[R] && leftRankIfRight <= r[R]);

        if (rightInvalid) { R--; continue; }

        cntL++; L++;
        cntR++; R--;
    }

    return cntL + cntR == m;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tests;
    while (tests--)
    {
        cin >> n;
        forn(i,n) cin >> l[i] >> r[i] >> u[i] >> v[i];

        int ans = 0;
        for (int m = n; m >= 0; m--)
        {
            if (check(m)) { ans = m; break; }
        }

        cout << ans << nl;
    }
    return 0;
}