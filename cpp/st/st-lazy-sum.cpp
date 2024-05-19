// Uses half-open intervals (inclusive of L but exclusive of R)
// Supports dynamic node creation
// Initialization: Node *st = new Node(v, 0, size(v));
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	ll zset = INF_LL, zadd = 0, val = 0;

	Node(int lo, int hi): lo(lo), hi(hi) {}
	Node(vl &v, int lo, int hi): lo(lo), hi(hi) {
		if (lo < hi - 1) {
			int mid = lo + (hi - lo) / 2;
			l = new Node(v, lo, mid), r = new Node(v, mid, hi);
			val = l->val + r->val;
		} else val = v[lo];
	}

	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			zset = x;
			zadd = 0;
			val = x * (hi - lo);
		} else {
			push();
			l->set(L, R, x), r->set(L, R, x);
			val = l->val + r->val;
		}
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (zset != INF_LL) zset += x;
			else zadd += x;
			val += x * (hi - lo);
		} else {
			push();
			l->add(L, R, x), r->add(L, R, x);
			val = l->val + r->val;
		}
	}

	void push() {
		if (!l) {
			int mid = lo + (hi - lo) / 2;
			l = new Node(lo, mid), r = new Node(mid, hi);
		}
		if (zset != INF_LL) {
			l->set(lo, hi, zset), r->set(lo, hi, zset);
			zset = INF_LL;
		} else {
			l->add(lo, hi, zadd), r->add(lo, hi, zadd);
			zadd = 0;
		}
	}
};