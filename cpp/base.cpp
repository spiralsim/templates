#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using mi2 = map<int, int>;
using pi2 = pair<int, int>;
using vi = vector<int>;
using v2i = vector<vi>;
using si = set<int>;
using vsi = vector<si>;
using vl = vector<ll>;
using v2l = vector<vl>;
using sl = set<ll>;
using qi = queue<int>;
using db = double;
using vd = vector<db>;
using v2d = vector<vd>;
using vb = vector<bool>;
using v2b = vector<vb>;

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

const int INF = 2'000'000'005;
const ll INF_LL = 4'000'000'000'000'000'005;

void solve(int i_, int t_) {

}

int main() {
	fastIO();
	int t_ = 1;
	cin >> t_;
	for (int i_ = 1; i_ <= t_; i_++) solve(i_, t_);
}