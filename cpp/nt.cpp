/**
 * Number Theory
 */

// Adapted from https://12tqian.github.io/cp-library/library/numerical/mod_int.cpp and Benjamin Qi

// Common moduli
const ll MOD1 = 1000000007, MOD2 = 998244353, MOD3 = 999999937, MOD4 = 9973;
ll MOD = MOD1; // The modulus used for most functions below

// Modular int (mi) that works in prime fields
typedef std::decay<decltype(MOD)>::type mod_t; 
struct mi {
	mod_t val;
    explicit operator mod_t () const { return val; }
    mi () { val = 0; }
    mi (const ll& v) { val = (v % MOD + MOD) % MOD; }
    friend ostream& operator << (ostream& os, const mi& a) { return os << a.val; }
    friend bool operator == (const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator != (const mi& a, const mi& b) { return !(a == b); }
    friend bool operator < (const mi& a, const mi& b) { return a.val < b.val; }
    mi operator - () const { return mi(-val); }
    mi& operator += (const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this;
	}
    mi& operator -= (const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this;
	}
    mi& operator *= (const mi& m) {
		val = (long long) val * m.val % MOD;
        return *this;
	}
    friend mi pow (mi a, ll p) {
        mi ans = 1;
		assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans;
	}
    friend mi inv (const mi& a) {
		assert(a != 0);
		return pow(a, MOD - 2);
	}
    mi& operator /= (const mi& m) { return (*this) *= inv(m); }
    friend mi operator + (mi a, const mi& b) { return a += b; }
    friend mi operator - (mi a, const mi& b) { return a -= b; }
    friend mi operator * (mi a, const mi& b) { return a *= b; }
    friend mi operator / (mi a, const mi& b) { return a /= b; }
};
mi mul2 (ll a, ll b) {
	mi ans = 1;
	for (ll i = a; i <= b; i++) ans *= i;
	return ans;
}
mi fact (ll a) { return mul2(1, a); }
mi npr (ll x, ll y) { return y <= x ? mul2(x - y + 1, x) : 0; } // Permute function
mi ncr (ll x, ll y) { return y <= x ? npr(x, y) / fact(y) : 0; } // Choose function