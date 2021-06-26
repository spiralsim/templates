/**
 * Base
 */

#include "bits/stdc++.h"
using namespace std;

typedef long long      ll ;
typedef double         db ;
typedef long double    ld ;
typedef pair<int, int> pii;
typedef map<int, int>  mii;
typedef set<int>       si ;
typedef string         str;
typedef vector<int>    vi ;
typedef vector<vi>     v2i;
typedef vector<si>     vsi;
typedef vector<ll>     vl ;
typedef vector<vl>     v2l;
typedef vector<db>     vd ;
typedef vector<bool>   vb ;
typedef vector<pii>    vp ;

void fastIO () {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
}
void fileIO (string file) {
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
}

// Debugging an arbitrary value or vector of values
template <class T>
void debug (string s, vector<T> a) {
	cout << "[Debug] " << s << " = ";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
		if (i < a.size() - 1) cout << ", ";
	}
	cout << '\n';
}
template <class T>
void debug (string s, T x) {
	debug(s, vector<T>({x}));
}
template <class T>
void debug (T x) {
	debug("*", x);
}

int main () {
	fastIO();
	
}