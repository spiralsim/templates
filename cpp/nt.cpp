/**
 * Number Theory
 * Dependencies: `#include <std/bitsc++.h>`
 */

// Adapted from https://github.com/12tqian/cp-library/blob/main/library/numerical/mod-int.hpp and Benjamin Qi
// (Copied July 25, 2021)

// Common primes: 1e9 + 7, 1e9 + 9, 998244353, 999999937, 9973

// Modular int (mi) that works in prime fields

const int MOD = 1e9 + 7;

typedef std::decay<decltype(MOD)>::type mod_t; 
struct mi {
	mod_t val;
	explicit operator mod_t() const { return val; }
	mi() { val = 0; }
	mi(const long long &v) {
		val = (-MOD <= v && v < MOD) ? v : v % MOD;
		if (val < 0) val += MOD; }
	friend std::istream& operator>>(std::istream &in, mi &a) { 
		long long x; std::cin >> x; a = mi(x); return in; }
	friend std::ostream& operator<<(std::ostream &os, const mi &a) { return os << a.val; }
	friend bool operator==(const mi &a, const mi &b) { return a.val == b.val; }
	friend bool operator!=(const mi &a, const mi &b) { return !(a == b); }    
	friend bool operator<(const mi &a, const mi &b) { return a.val < b.val; }
	friend bool operator>(const mi &a, const mi &b) { return a.val > b.val; }
	friend bool operator<=(const mi &a, const mi &b) { return a.val <= b.val; }
	friend bool operator>=(const mi &a, const mi &b) { return a.val >= b.val; }
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi &m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator-=(const mi &m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator*=(const mi &m) { val = (long long)val * m.val % MOD;
		return *this; }
	friend mi pow(mi a, long long p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; }
	friend mi inv(const mi &a) { assert(a != 0); return pow(a, MOD - 2); }
	mi& operator/=(const mi &m) { return (*this) *= inv(m); }
	friend mi operator+(mi a, const mi &b) { return a += b; }
	friend mi operator-(mi a, const mi &b) { return a -= b; }
	friend mi operator*(mi a, const mi &b) { return a *= b; }
	friend mi operator/(mi a, const mi &b) { return a /= b; }
};

// Added by jt4517
mi mul2 (long long a, long long b) {
	mi ans = 1;
	for (long long i = a; i <= b; i++) ans *= i;
	return ans;
}
mi fact (long long a) { return mul2(1, a); }
mi npr (long long x, long long y) { return y <= x ? mul2(x - y + 1, x) : 0; } // Permute function
mi ncr (long long x, long long y) { return y <= x ? npr(x, y) / fact(y) : 0; } // Choose function

typedef std::vector<mi> vm;
typedef std::vector<vm> v2m;