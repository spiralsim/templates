// Must use 0 as root
struct LCA {
	v2i g;
	int n, l;
	int l = ceil(log2(n));
	v2i up;
	int timer = 0;
	vi tin, tout, d; // d is depth from the root

	LCA(v2i &g):
		g(g),
		n(g.size()),
		l(ceil(log2(n))),
		up(n, vi(l + 1)),
		tin(n),
		tout(n),
		d(n)
	{}

	void dfs(int u, int p) {
		d[u] = p == -1 ? 0 : d[p] + 1;

		up[u][0] = p;
		for (int i = 1; i <= l; i++)
			up[u][i] = up[up[u][i - 1]][i - 1];

		tin[u] = ++timer;
		for (int v: g[u]) if (v != p) dfs(v, u);
		tout[u] = ++timer;
	};
	// dfs(0, 0); // initialize

	bool is_anc(int u, int v) {
		return tin[u] <= tin[v] && tout[v] <= tout[u];
	};

	int lca(int u, int v) {
		if (is_anc(u, v)) return u;
		else if (is_anc(v, u)) return v;
		else {
			for (int i = l; i >= 0; i--)
				if (!is_anc(up[u][i], v))
					u = up[u][i];
			return up[u][0];
		}
	};

	int dist(int u, int v) {
		return d[u] + d[v] - 2 * d[lca(u, v)];
	}
};
