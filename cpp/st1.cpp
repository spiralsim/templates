/**
 * Segment Tree 1
 */

struct ST {
	struct STN {
		int l, r, m;
		STN *chd[2]; // Children
		
		STN (int l, int r) {
			this->l = l, this->r = r, this->m = (l + r) / 2;
			if (l < r) chd[0] = new STN(l, m), chd[1] = new STN(m + 1, r);
		}
	};
	
	STN *root;
	
	ST (int n) {
		root = new STN(0, n - 1);
	}
};