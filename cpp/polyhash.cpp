const long long X1 = 9973, X2 = 9974;

struct PolyHash {
	vm hsh1, hsh2, p1, p2;

	PolyHash(std::string s) {
		int N = s.size();
		hsh1 = hsh2 = p1 = p2 = vm(N + 1);
		p1[0] = p2[0] = 1;
		for (int i = 0; i < N; i++) {
			hsh1[i + 1] = hsh1[i] * X1 + (s[i] - 'a');
			hsh2[i + 1] = hsh2[i] * X2 + (s[i] - 'a');
			p1[i + 1] = p1[i] * X1;
			p2[i + 1] = p2[i] * X2;
		}
	}

	pair<mi, mi> getHash(int a, int k) {
		return {
			hsh1[a + k] - hsh1[a] * p1[k],
			hsh2[a + k] - hsh2[a] * p2[k]
		};
	}
};