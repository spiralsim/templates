struct DSU {
	std::vector<int> p, r; // Parents and ranks/depths of elements
	int cnt; // Count of disjoint sets

	DSU(int n) {
		for (int i = 0; i < n; i++) p.push_back(i);
		r.resize(n);
		cnt = n;
	}

	// Stores a change for rollback later
	struct change {
		int a;
		int inc;

		change(int a, int inc) {
			this->a = a;
			this->inc = inc;
		}

		void undo(DSU *d) {
			d->p[a] = a;
			if (inc != -1) d->r[inc]--;
			d->cnt++;
		}
	};
	std::stack<change> changes;
	std::stack<int> cpts; // Checkpoints
	
	int get(int a) {
		return p[a] = a == p[a] ? a : get(p[a]);
	}
	// Union of a and b
	void uni(int a, int b) {
		a = get(a), b = get(b);
		if (a == b) return;
		if (r[b] < r[a]) std::swap(a, b);
		int inc = -1;
		if (r[b] == r[a]) {
			inc = b;
			r[b]++;
		}
		if (cpts.size()) {
			changes.emplace(a, inc);
			cpts.top()++;
		}
		p[a] = b;
		cnt--;
	}
	// Create checkpoint
	void save() {
		cpts.push(0);
	}
	// Roll back to last checkpoint
	void rollback() {
		if (cpts.empty()) return;
		while (cpts.top()--) {
			changes.top().undo(this);
			changes.pop();
		}
		cpts.pop();
	}
};