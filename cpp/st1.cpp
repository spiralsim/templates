/**
 * Segment Tree 1
 * Dependencies: None
 */

struct ST {
	int l, r, m;
	ST *chd[2]; // Children
	
	ST(int l, int r) {
		this->l = l, this->r = r, this->m = (l + r) / 2;
		if (l < r) chd[0] = new ST(l, m), chd[1] = new ST(m + 1, r);
	}
};

/* END OF ST1 TEMPLATE */