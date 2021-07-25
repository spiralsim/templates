/**
 * Base
 * Dependencies: None
 */

#include <bits/stdc++.h>
using namespace std;

#define td typedef
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

// Some macros borrowed from Timothy Qian's template
// https://github.com/12tqian/cp-library/blob/main/library/contest/template_full.cpp
#define f1r(i, a, b) for (int i = (a); i < (b); i++)
#define f0r(i, a) f1r(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define each(a, x) for (auto &a: x)

td long long ll;
td double db;
td pair<int, int> pii;
td map<int, int> mii;
td set<int> si;
td string str;
td vector<int> vi;
td vector<vi> v2i;
td vector<si> vsi;
td vector<ll> vl;
td vector<vl> v2l;
td vector<db> vd;
td vector<bool> vb;
td vector<pii> vp;

void fastIO () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
}
void fileIO (string file) {
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
}

// Debugging an arbitrary value or vector of values
template <class T>
void debug (string s, vector<T> a) {
	cerr << "[Debug] " << s << " = ";
	for (int i = 0; i < a.size(); i++) {
		cerr << a[i];
		if (i < a.size() - 1) cerr << ", ";
	}
	cerr << '\n';
}
template <class T>
void debug (string s, T x) {
	debug(s, vector<T>({x}));
}
template <class T>
void debug (T x) {
	debug("*", x);
}

void solve () {

}

int main () {
	fastIO();
	int T = 1;
	cin >> T;
	while (T--) solve();
}