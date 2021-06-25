/**
 * Number theory template
 */

// Common moduli
const ll MOD1 = 1000000007, MOD2 = 998244353, MOD3 = 999999937, MOD4 = 9973;
ll MOD = MOD1; // The modulus used for most functions below
// a^n (mod m)
ll mexp (ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n & 1) res = res * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return res;
}
// Inverse of a (mod p) by Fermat's little theorem
ll inv (ll a, ll p) {
	return mexp(a, p - 2, p);
}
// x + y (mod MOD)
ll ma (ll x, ll y) {
	return (x + y) % MOD;
}
// x - y (mod MOD)
ll ms (ll x, ll y) {
	return ma(ma(x, -y), MOD);
}
// xy (mod MOD)
ll mm (ll x, ll y) {
	return (x * y) % MOD;
}
// x/y = xy^(-1) (mod MOD)
ll md (ll x, ll y) {
	return mm(x, inv(y, MOD));
}
// x^y (mod MOD)
ll me (ll x, ll y) {
	return mexp(x, y, MOD);
}
// y!/x! (mod MOD)
ll mm2 (ll x, ll y) {
	ll res = 1;
	for (ll i = x; i <= y; i++) res = mm(res, i);
	return res;
}
// x! (mod MOD)
ll mf (ll x) {
	return mm2(1, x);
}
// x permute y (mod MOD)
ll mp (ll x, ll y) {
	return y <= x ? mm2(x - y + 1, x) : 0;
}
// x choose y (mod MOD)
ll mc (ll x, ll y) {
	return y <= x ? md(mp(x, y), mf(y)) : 0;
}