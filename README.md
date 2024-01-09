# CP Templates

This is a compilation of all templates I regularly use for competitive programming (CP) contests. It assumes you are using GCC v13 and Python 3.11.

## C++ (`/cpp/`)
| Template | File | Description | Dependencies |
| - | - | - | - |
| Base | `base.cpp` | Basic environment configuration, common typedefs, and helper functions; can be independently run as a full program. **Start every program from this.** | None |
| DSU 1 | `dsu1.cpp` | Disjoint set union (DSU) with persistence and rollback. | None |
| DSU 2 | `dsu2.cpp` | DSU with dynamic connectivity offline (DCO). | DSU 1 |
| Number Theory | `nt.cpp` | Common constants and a `mi` struct with mathematical operations for modular arithmetic | None |
| Segment Tree 1 | `st1.cpp` | Basic segment tree data structure | None |
| Segment Tree 2 | `st2.cpp` | Segment tree with methods to add to a single element and get the sum over a segment. Easy to generalize to many common applications. | None |
| LCA | `lca.cpp` | Lowest common ancestor (LCA) with binary lifting | None |
| Polynomial Hash | `polyhash.cpp` | Polynomial Hash function template | Number Theory |


## Python (`/py/`)
| Template | File | Description | Dependencies |
| - | - | - | - |
| Base | `base.py` | Basic environment configuration, including setup for multitests; can be independently run as a full program. **Start every program from this.** | None |