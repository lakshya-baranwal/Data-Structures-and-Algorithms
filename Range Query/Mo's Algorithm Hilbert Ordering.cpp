#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int BLOCK;

// Compute the Hilbert order (Hilbert curve index) of a 2D point (x, y)
// The Hilbert curve maps a 2D grid to 1D in a way that preserves spatial locality
inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) return 0;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query {
    int l, r, idx;
    int64_t ord;

    void computeOrder(int maxPow) {
        ord = hilbertOrder(l, r, maxPow, 0);
    }

    bool operator<(const Query &other) const {
        return ord < other.ord;
    }
};

int arr[MAXN], answer[MAXN], freq[MAXN];
int unique_count = 0;

void add(int x) {
    if (++freq[x] == 1) unique_count++;
}

void remove(int x) {
    if (--freq[x] == 0) unique_count--;
}

int main() {
    int n, q;
    cin >> n >> q;
    int maxPow = 0;
    while ((1 << maxPow) < n) maxPow++;

    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
        queries[i].computeOrder(maxPow);
    }

    sort(queries.begin(), queries.end());

    int l = 0, r = -1;
    for (auto &query : queries) {
        while (l > query.l) add(arr[--l]);
        while (r < query.r) add(arr[++r]);
        while (l < query.l) remove(arr[l++]);
        while (r > query.r) remove(arr[r--]);
        answer[query.idx] = unique_count;
    }

    for (int i = 0; i < q; i++) cout << answer[i] << "\n";
}

/*
 * Hilbert Curve Explanation:
 * ---------------------------
 * The Hilbert curve is a continuous fractal space-filling curve. It maps a 2D grid (of size 2^k x 2^k)
 * to a 1D line while preserving spatial locality — meaning that points close together in 2D remain close in 1D.
 *
 * Mathematically, for each recursive level pow (2^pow grid size), the curve subdivides the square into 4 quadrants,
 * visiting them in a fixed pattern depending on the rotation state.
 *
 * In Mo's algorithm, sorting queries by Hilbert order (based on their [l, r] coordinates) minimizes the number
 * of changes in the data structure between queries. This often results in better cache locality and significantly
 * faster runtime compared to standard sqrt-decomposition sorting.
 *
 * Reference:
 * - https://codeforces.com/blog/entry/61203 (Explanation of Hilbert order and its application in Mo's algorithm)
 */
