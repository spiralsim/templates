/** 
 * Segment Tree 2
 * Dependencies: None
 */

struct ST {
	int l, r, m;
	int sum = 0;
	ST *chd[2]; // Children

	ST(int l, int r) {
		this->l = l, this->r = r, this->m = (l + r) / 2;
		if (l < r) chd[0] = new ST(l, m), chd[1] = new ST(m + 1, r);
	}

	void add(int i, int x) {
		if (l == r) sum += x;
		else {
			if (i <= m) chd[0]->add(i, x);
			else chd[1]->add(i, x);
			sum = chd[0]->sum + chd[1]->sum;
		}
	}
	int getSum(int l, int r) {
		if (l > r) return 0;
		if (l == this->l && r == this->r) return sum;
		else if (r <= this->m) return chd[0]->getSum(l, r);
		else if (l > this->m) return chd[1]->getSum(l, r);
		else return chd[0]->getSum(l, m) + chd[1]->getSum(m + 1, r);
	}
};

/*
END OF ST2 TEMPLATE 
 */