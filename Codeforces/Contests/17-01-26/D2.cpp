#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define folr(i, a, n) for (auto i = (a); i <= (n); ++i)
#define forl(i, n, a) for (auto i = (n); i >= (a); --i)
using namespace std;
using ll = long long;

#define MILF

string to_string(char v) {
	string a = ""; a += v;
	return a;
}

template<class A> string to_string(const A& v) {
	string s = "{";
	for (const auto& x : v) s += (sz(s) > 1 ? ", " : "") + to_string(x);
	return s += "}";
}

void debug_out() { cerr << '\n'; }
template<class U, class... T> void debug_out(const U& x, const T&... args) {
	cerr << ' ' << to_string(x);
	debug_out(args...);
}

mt19937 rng(__builtin_ia32_rdtsc());
template<class T> T rnd(T a, T b) { return uniform_int_distribution<T>(a, b)(rng); }

#define sc(x) cerr << "\033[" << x << "m"
#define debug(...) //sc(91), cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__), sc(39)

int f[106][106][106], C[206][206];
const int mod = 998244353;

void solve(const int& ic) {
	memset(f, 0, sizeof f);
	int n; cin >> n;
	string s; cin >> s; s = ' ' + s;
	f[0][0][0] = 1;
	folr(i, 1, n) {
		folr(l, 0, n) {
			folr(j, 0, i) f[i][l][j] = f[i - 1][l][j];
			if(!l) continue;
			if(s[i] == '(')
				folr(j, 1, i) f[i][l][j] = (f[i][l][j] + f[i - 1][l - 1][j - 1]) % mod;
			if(s[i] == ')')
				folr(j, 0, i) f[i][l][j] = (f[i][l][j] + f[i - 1][l - 1][j + 1]) % mod;
//			folr(j, 0, i) debug(i, l, j, f[i][l][j]);
		}
	}
	int u = 0, ans = 0;
	forl(i, n, 1) {
		if(s[i] == ')') ++u;
		else {
			debug(i, ans);
			folr(l, 0, n)
				folr(j, 0, u - 1) {
					debug(l, j, u, f[i - 1][l][j], C[u][j + 1]);
					ans = (ans + 1ll * f[i - 1][l][j] * (l + j) % mod * C[u][j + 1]) % mod;
					debug(f[i - 1][l][j], l, C[u][j + 1]);
				}
			int g = 0;
			debug(i, ans);
			folr(j, 1, i - 1) {
				if(s[j] == '(') {
					++g;
					int t = 0;
					folr(k, j + 1, i - 1)
						if(s[k] == ')') ++t;
					debug(i, j, g, u, t, ans);
					folr(k, 1, g) 
						ans = (ans + mod - 1ll * C[g - 1][k - 1] 
											   * (C[u + t][k + 1] - C[t][k + 1] + mod) % mod 
											   * (k + k)% mod) % mod;
					debug(i, j, ans);
				}
			}
			debug(i, ans);
		}
	}
	cout << ans << '\n';
}


int main() {
	#ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	folr(i, 0, 200) {
		C[i][0] = 1;
		folr(j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod; 
	}
	int tt = 1; 
	cin >> tt;
	folr(ic, 0, tt - 1) solve(ic);
}