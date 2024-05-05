template <class T> struct ST {
	T U = 2e9 + 5;
	T f(T a, T b) { return min(a, b); }
	int n;
	vector<T> t;
	
	ST(int n): n(n), t(4 * n, U) {}

	void upd(int v, int tl, int tr, int i, T x) {
		if (tl == tr) t[v] = x;
		else {
			int tm = (tl + tr) / 2;
			if (i <= tm) upd(2 * v, tl, tm, i, x);
			else upd(2 * v + 1, tm + 1, tr, i, x);
			t[v] = f(t[2 * v], t[2 * v + 1]);
		}
	}
	void upd(int i, T x) { upd(1, 0, n - 1, i, x); }
	T query(int v, int tl, int tr, int l, int r) {
		if (l > r) return U;
		if (l == tl && r == tr) return t[v];
		int tm = (tl + tr) / 2;
		return f(
			query(2 * v, tl, tm, l, min(r, tm)),
			query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)
		);
	}
	T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};