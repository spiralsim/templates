/**
 * LCA
 * Dependencies: `#include <std/bitsc++.h>`
 */

// Adapted from https://cp-algorithms.com/graph/lca_binary_lifting.html
// (Copied July 25, 2021)
int N, L;
std::vector<std::vector<int>> adj;

int timer;
std::vector<int> tIn, tOut;
std::vector<std::vector<int>> up;

void dfs(int u, int p) {
    tIn[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i <= L; i++) up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v: adj[u]) {
        if (v != p) dfs(v, u);
    }

    tOut[u] = ++timer;
}

bool isAnc(int u, int v) { // isAncestor
    return tIn[u] <= tIn[v] && tOut[u] >= tOut[v];
}

int lca(int u, int v) {
    if (isAnc(u, v)) return u;
    if (isAnc(v, u)) return v;
    for (int i = L; i >= 0; i--) {
        if (!isAnc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void prepLCA(int r) { // Preprocess with r as the root 
    assert(adj.size());
    tIn.resize(N);
    tOut.resize(N);
    timer = 0;
    L = ceil(log2(N));
    up.assign(N, std::vector<int>(L + 1));
    dfs(r, r);
}