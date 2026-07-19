#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
#define sz(x) ((int) x.size())
#define pb push_back
#define nl '\n'
#define MILF

using namespace std;

int tests;

// suma de dígitos de x, sin strings
int digit_sum(int x) {
    int s = 0;
    while(x > 0) { s += x%10; x /= 10; }
    return s;
}

// agrega los dígitos de x al array cnt
void add_digits(int x, int cnt[10], int sign) {
    while(x > 0) { cnt[x%10] += sign; x /= 10; }
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tests;

    while (tests--)
    {
        string s; cin >> s;

        if(sz(s) == 1) { cout << s << nl; continue; }

        int count[10] = {};
        forn(i, sz(s)) count[s[i]-'0']++;

        forr(i, 1, 9*sz(s)+1)
        {
            // construir suffix_count sin strings
            int suffix_count[10] = {};
            add_digits(i, suffix_count, +1);

            int cur = i;
            while(cur >= 10) {
                cur = digit_sum(cur);
                add_digits(cur, suffix_count, +1);
            }

            // chequear que hay suficientes dígitos
            int remaining[10];
            bool ok = true;
            forn(j, 10) {
                remaining[j] = count[j] - suffix_count[j];
                if(remaining[j] < 0) { ok = false; break; }
            }
            if(!ok) continue;

            // chequear que los dígitos restantes suman exactamente i
            int rem_sum = 0;
            forn(j, 10) rem_sum += j * remaining[j];
            if(rem_sum != i) continue;

            // construir respuesta — solo llegamos aquí una vez
            string ans;
            ans.reserve(sz(s));

            // prefix: dígitos restantes en orden no creciente
            dforn(j, 10)
                forn(k, remaining[j])
                    ans += (char)('0' + j);

            // suffix: reconstruir una sola vez para el output
            int x = i;
            while(x >= 10) {
                // agregar dígitos de x
                string tmp = to_string(x); // solo para output, fuera del loop caliente
                ans += tmp;
                x = digit_sum(x);
            }
            ans += (char)('0' + x);

            cout << ans << nl;
            break;
        }
    }

    return 0;
}