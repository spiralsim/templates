template <class T> struct ST {
	static constexpr U = 2e9 + 5;
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
	T query(int v, int tl, int tr, int l, int r) {
		if (l > r) return U;
		int tm = (tl + tr) / 2;
		return f(
			query(2 * v, tl, tm, l, min(r, tm)),
			query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)
		);
	}
};