#include <bits/stdc++.h>
using namespace std;
#define MILF
constexpr int N = 1e4+5;
int n, id[N], cnt[N];
bool vs[N], e[N][N];
struct Dsu {
	int fa[N];
	void init(int n) {
		for (int i = 1; i <= n; i++) fa[i] = i;
	}
	int find(int x) {
		if (x == fa[x]) return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int x, int y) {
		fa[find(x)] = find(y);
	}
} dsu;
bool reach[N];
vector<int> tree[N];
void search(int u) {
	reach[u] = 1;
	for (int v : tree[u]) {
		search(v);
	}
}
void solve(int tid) {
	cin >> n;
	for (int i = 1; i <= n; i++) cnt[i] = 0, tree[i].clear();
	for (int u = 1; u <= n; u++) {
		id[u] = u;
		string s;
		cin >> s;
		for (int v = 1; v <= n; v++) {
			e[u][v] = s[v-1]-'0';
			cnt[u] += e[u][v];
		}
	}
	sort(id + 1, id + n + 1, [&](int u, int v) {
		return cnt[u] > cnt[v];
	});
	vector<pair<int, int >> edges;
	for (int u = 1; u <= n; u++) {
		for(int i = 1; i <= n; i++) {
			vs[i] = false;
		}
		vs[u] = true;
		for (int i = 1; i <= n; i++) {
			int v = id[i];
			if (!vs[v] && e[u][v]) {
				edges.push_back({u, v});
				if(edges.size() >= n) {
					cout << "No" << "\n";
					return ;
				}
				for (int w = 1; w <= n; w++) {
					if (e[v][w]) {
						vs[w] = true;
					}
				}
			}
		}
	}
	if (edges.size() != n - 1) {
		cout << "No" << "\n";
		return ;
	}
	sort(edges.begin(), edges.end());
	dsu.init(n);
	for (auto [u, v] : edges) {
		dsu.merge(u, v);
		tree[u].push_back(v);
	}
	int flag = 1;
	for (int i = 1; i <= n; i++) flag &= (dsu.find(i) == dsu.find(1));
	if (!flag) {
		cout << "No" << "\n";
		return ;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) reach[j] = 0;
		search(i);
		for (int j = 1; j <= n; j++) {
			if (reach[j] != e[i][j]) {
				cout <<  "No" << "\n";
				return ;
			}
		}
	}
	cout<< "Yes\n";
	for (auto [u, v] : edges) {
		cout << u << ' ' << v << '\n';
	}
}

int main() {
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}