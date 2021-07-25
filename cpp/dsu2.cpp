/**
 * DSU 2
 * Dependencies: DSU 1
 */

struct query {
	char op; // Operation (! = count components, anything else = toggle edge)
	int t;
	int u, v;

	query (char op, int t, int u = -1, int v = -1) {
		this->op = op;
		this->t = t;
		this->u = u, this->v = v;
	}
};

// Represents a time segment on which an edge exists
struct seg {
	int u, v;
	int l, r;

	seg (int u, int v, int l, int r) {
		this->u = u, this->v = v;
		this->l = l, this->r = r;
	}
};

// A segment tree on the timeline
struct ST {
	struct STN {
		int l, r, m;
		STN *chd[2];
		vector<seg> segs;

		STN (int l, int r) {
			this->l = l, this->r = r, this->m = (l + r) / 2;
			if (l < r) chd[0] = new STN(l, m), chd[1] = new STN(m + 1, r);
		}

		// Process a time segment on which an edge exists
		void apply (int l, int r, seg s) {
			if (l == this->l && r == this->r) segs.push_back(s);
			else if (r <= this->m) chd[0]->apply(l, r, s);
			else if (l > this->m) chd[1]->apply(l, r, s);
			else chd[0]->apply(l, m, s), chd[1]->apply(m + 1, r, s);
		}
		// Fully process this time segment and store component counts
		void proc (DSU *d, vi &cntT) {
			d->save();
			for (seg s: segs) d->uni(s.u, s.v);
			if (l == r) cntT[l] = d->cnt;
			else chd[0]->proc(d, cntT), chd[1]->proc(d, cntT);
			d->rollback();
		}
	};
	STN *root;

	ST (int n) {
		root = new STN(0, n - 1);
	}

	void apply (seg s) {
		root->apply(s.l, s.r, s);
	}
	void proc (DSU *d, vi &ans) {
		root->proc(d, ans);
	}
};

int main () {
	fastIO();
	vector<query> queries;
	int t;

	vector<seg> segs;
	map<pii, int> unpaired; // Unpaired time segments for edges
	for (query qu: queries) {
		if (qu.op == '!') {
			pii p = {qu.u, qu.v};
			if (!unpaired[p]) unpaired[p] = qu.t;
			else {
				segs.emplace_back(qu.u, qu.v, unpaired[p], qu.t - 1);
				unpaired.erase(p);
			}
		}
	}
	for (pair<pii, int> mp: unpaired) {
		pii p = mp.first;
		segs.emplace_back(p.first, p.second, mp.second, t);
	}
	DSU *dsu = new DSU(n);
	vi cntT(e + 1); // Component counts at each time point
	ST *st = new ST(e + 1);
	for (seg s: segs) st->apply(s);
	st->proc(dsu, cntT);
}