// nxn 2D Segment Tree (ST of ST) - Remember to change f for both ST and ST2!
// Build: O(n^2), O(n^2 log^2 n) with initialized values
// Upd and query: O(log^2 n)
template <class T> struct ST2 {
	T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); }
	int n;
	vector<ST<T>> t;
	
	ST2(int n): n(n), t(2 * n, ST<T>(n)) {}

	// i is a 0-indexed position (row), j is a 0-indexed col, x is the new value
	void upd(int i, int j, T x) {
		i += n;
		t[i].upd(j, x);
		for (i /= 2; i; i /= 2)
			t[i].upd(j, f(t[2 * i].t[j + n], t[2 * i + 1].t[j + n]));
	}
	// a and b are 0-indexed closed interval bounds for rows and cols
	T query(int ar, int br, int ac, int bc) {
		T ra = unit, rb = unit;
		for (ar += n, br += n; ar <= br; ar /= 2, br /= 2) {
			if (ar % 2 == 1) ra = f(ra, t[ar++].query(ac, bc));
			if (br % 2 == 0) rb = f(t[br--].query(ac, bc), rb);
		}
		return f(ra, rb);
	}
};