// Build: O(n), O(n log n) with initialized values
// Upd and query: O(log n)
template <class T> struct ST {
	T unit = INT_MAX; // min: INT/LLONG_MAX, max: INT/LLONG_MIN, sum: 0
	T f(T a, T b) { return min(a, b); } // Change this if needed
	int n;
	vector<T> t;
	
	ST(int n): n(n), t(2 * n, unit) {}

	// i is a 0-indexed position, x is the new value
	void upd(int i, T x) {
		i += n;
		t[i] = x;
		for (i /= 2; i; i /= 2) t[i] = f(t[2 * i], t[2 * i + 1]);
	}
	// Queries for the half-open interval [b, e) with 0-indexed bounds
	T query(int b, int e) {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, t[b++]);
			if (e % 2) rb = f(t[--e], rb);
		}
		return f(ra, rb);
	}
};