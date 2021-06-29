/** 
 * Segment Tree 2
 */

struct ST {
	struct STN {
		int l, r, m;
		int sum = 0;
		STN *chd[2]; // Children

		STN (int l, int r) {
			this->l = l, this->r = r, this->m = (l + r) / 2;
			if (l < r) chd[0] = new STN(l, m), chd[1] = new STN(m + 1, r);
		}

		void add (int i, int x) {
			if (l == r) sum += x;
			else {
				if (i <= m) chd[0]->add(i, x);
				else chd[1]->add(i, x);
				sum = chd[0]->sum + chd[1]->sum;
			}
		}
		int getSum (int l, int r) {
			if (l == this->l && r == this->r) return sum;
			else if (r <= this->m) return chd[0]->getSum(l, r);
			else if (l > this->m) return chd[1]->getSum(l, r);
			else return chd[0]->getSum(l, m) + chd[1]->getSum(m + 1, r);
		}
	};
	
	STN *root;
	
	ST (int n) {
		root = new STN(0, n - 1);
	}

	void add (int i, int x) {
		root->add(i, x);
	}
	int getSum (int l, int r) {
		return root->getSum(l, r);
	}
};