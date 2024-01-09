#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef map<int, int> mi2;
typedef pair<int, int> pi2;
typedef vector<pi2> vp;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef set<int> si;
typedef vector<si> vsi;
typedef vector<ll> vl;
typedef vector<vl> v2l;
typedef set<ll> sl;
typedef double db;
typedef vector<db> vd;
typedef vector<vd> v2d;
typedef vector<bool> vb;
typedef vector<vb> v2b;

// https://usaco.guide/gold/PURS?lang=cpp#finding-the-k-th-element
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fi first
#define se second
#define all(x) begin(x), end(x)

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
}
// // Commented out by default to avoid compiler warnings
// void fileIO(string file) {
// 	freopen((file + ".in").c_str(), "r", stdin);
// 	freopen((file + ".out").c_str(), "w", stdout);
// }

template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& p) { 
	return os << "(" << p.first << ", " << p.second << ")"; 
}
template <
	typename C,
	typename T = decay<decltype(*begin(declval<C>()))>,
	typename enable_if<!is_same<C, string>::value>::type* = nullptr
>
ostream& operator << (ostream& os, const C& c) { 
	bool f = true; 
	os << "{"; 
	for (const auto& x : c) { 
		if (!f) os << ", "; 
		f = false;
		os << x;
	} 
	return os << "}"; 
}
template <typename T>
void debug(string s, T x) {
	cerr << s << " = " << x << "\n";
}
template <typename T, typename... Args>
void debug(string s, T x, Args... args) { 
	cerr << s.substr(0, s.find(',')) << " = " << x << " | ";
	debug(s.substr(s.find(',') + 2), args...);
}

void solve(int __i, int __t) {

}

int main() {
	fastIO();
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) solve(i, t);
}