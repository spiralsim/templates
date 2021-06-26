/**
 * Number Theory
 */

// Adapted from https://12tqian.github.io/cp-library/library/numerical/mod_int.cpp and Benjamin Qi

// Common moduli
const ll MOD1 = 1000000007, MOD2 = 998244353, MOD3 = 999999937, MOD4 = 9973;
ll MOD = MOD1; // The modulus used for most functions below

// Modular int (mint) that works in prime fields
typedef std::decay<decltype(MOD)>::type mod_t; 
struct mint {
	mod_t val;
    explicit operator mod_t () const { return val; }
    mint () { val = 0; }
    mint (const ll& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
	}
    friend ostream& operator << (ostream& os, const mint& a) { return os << a.val; }
    friend bool operator == (const mint& a, const mint& b) { return a.val == b.val; }
    friend bool operator != (const mint& a, const mint& b) { return !(a == b); }
    friend bool operator < (const mint& a, const mint& b) { return a.val < b.val; }
    mint operator - () const { return mint(-val); }
    mint& operator += (const mint& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this;
	}
    mint& operator -= (const mint& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this;
	}
    mint& operator *= (const mint& m) {
		val = (long long) val * m.val % MOD;
        return *this;
	}
    friend mint pow (mint a, ll p) {
        mint ans = 1;
		assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans;
	}
    friend mint inv (const mint& a) {
		assert(a != 0);
		return pow(a, MOD - 2);
	}
    mint& operator /= (const mint& m) { return (*this) *= inv(m); }
    friend mint operator + (mint a, const mint& b) { return a += b; }
    friend mint operator - (mint a, const mint& b) { return a -= b; }
    friend mint operator * (mint a, const mint& b) { return a *= b; }
    friend mint operator / (mint a, const mint& b) { return a /= b; }
};
mint mul2 (ll a, ll b) {
	mint ans = 1;
	for (ll i = a; i <= b; i++) ans *= i;
	return ans;
}
mint fact (ll a) { return mul2(1, a); }
mint npr (ll x, ll y) { return y <= x ? mul2(x - y + 1, x) : 0; } // Permute function
mint ncr (ll x, ll y) { return y <= x ? npr(x, y) / fact(y) : 0; } // Choose function