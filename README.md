# CP Templates

These are some templates I use for competitive programming (CP) contests. It assumes G++23 and Python 3.11.

For each language, it's implied that every program should be started from the `Base` template.

Some are inspired by these sources:
- [CPH: Competitive Programming Handbook](https://cses.fi/book/book.pdf)
- [KACTL: KTH Algorithm Competition Template Library](https://github.com/kth-competitive-programming/kactl/blob/main/kactl.pdf)
- [CSES: Code Submission Evaluation System Problemset](https://cses.fi/problemset/)

## C++ (`/cpp/`)
| Template | File | Description | Dependencies | Inspirations |
| - | - | - | - | - |
| Base | `base.cpp` | | | |
| DSU 1 | `dsu1.cpp` | Disjoint set union (DSU) with persistence and rollback. | | |
| DSU 2 | `dsu2.cpp` | DSU with dynamic connectivity offline (DCO). | <ul><li>DSU 1</li></ul> | |
| Number Theory | `nt.cpp` | Common constants and a `mi` struct with mathematical operations for modular arithmetic | | |
| ST - Simple | `st.cpp` | Simple segment tree for point update and range queries (`min` by default). Customize by changing `T`, `unit`, and `f`. | | <ul><li>CPH Segment Tree (pp. 91)</li><li>KACTL SegmentTree.h (pp. 3)</li></ul>
| ST - Simple 2D | `st2.cpp` | 2D simple segment tree for point update and range queries (`min` by default). Customize by changing `T`, `unit`, and `f` to the same values as the 1D `ST`. | <ul><li>ST - Simple</li></ul> | <ul><li>CPH Segment Tree Two-dimensionality (pp. 274)</li><li>KACTL FenwickTree2d.h (pp. 4)</li></ul> |
| ST - Lazy Prop - Sum | `st-lazy-sum.cpp` | Segment tree with methods to assign a range, add to a range, and query the sum of a range using lazy propagation. Also supports dynamic node creation. | | <ul><li>KACTL LazySegmentTree.h (pp. 3)</li><li>CSES (Range Updates and Sums)</li></ul> |
| LCA | `lca.cpp` | Lowest common ancestor (LCA) with binary lifting, depth, and distance function | | <ul><li>CPH Lowest Common Ancestor (pp. 177-180)</li><li>KACTL LCA.h (pp. 15)</li></ul> |
| Polynomial Hash | `polyhash.cpp` | Polynomial Hash function template | <ul><li>Number Theory</li></ul> | |

## Python (`/py/`)
| Template | File | Description | Dependencies |
| - | - | - | - |
| Base | `base.py` | | |