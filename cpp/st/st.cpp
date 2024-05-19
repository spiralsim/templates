// Build: O(n), O(n log n) with initialized values
// Upd and query: O(log n)
template <class T> struct ST {
	T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); }
	int n;
	vector<T> t;
	
	ST(int n): n(n), t(2 * n, unit) {}

	// i is a 0-indexed position, x is the new value
	void upd(int i, T x) {
		i += n;
		t[i] = x;
		for (i /= 2; i; i /= 2) t[i] = f(t[2 * i], t[2 * i + 1]);
	}
	// a and b are 0-indexed closed interval bounds
	T query(int a, int b) {
		T ra = unit, rb = unit;
		for (a += n, b += n; a <= b; a /= 2, b /= 2) {
			if (a % 2 == 1) ra = f(ra, t[a++]);
			if (b % 2 == 0) rb = f(t[b--], rb);
		}
		return f(ra, rb);
	}
};