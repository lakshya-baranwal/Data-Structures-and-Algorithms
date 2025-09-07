/*
 * Binary Indexed Tree (Fenwick Tree) implementation.
 *
 * Key Points:
 * - Externally uses 0-based indexing.
 *   All queries and updates should use indices 0..n-1.
 * - Internally, the tree array uses 1-based indexing for efficient BIT operations.
 * - Supports:
 *     1. Point add: add(idx, val)
 *     2. Point set: set(idx, val)
 *     3. Prefix sum: sum(idx)
 *     4. Range sum: sum(l, r)
 *     5. Build from array: work(a)
 */


template<class T> class BIT {
    int n;              // size of array
    vector<T> tree;   // internal BIT array
    vector<T> arr;
    inline int lowbit(int x) { return x & -x; }  // helper function

public:
    BIT(int n) {
        this->n = n;
        tree.assign(n + 1, 0);  // 1-based indexing
        arr.assign(n, 0); // 0-based indexing externally
    }

    // add value 'val' at index 'idx' (O(log n))
    void add(int idx, T val) {
        arr[idx] += val;
        idx++;
        while (idx <= n) {
            tree[idx] += val;
            idx += lowbit(idx);
        }
    }

    void set(int idx, T val) {
        T delta = val - arr[idx];
        add(idx, delta);
    }

    // prefix sum from 0..idx (O(log n))
    T sum(int idx) {
        idx++;
        T res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= lowbit(idx);
        }
        return res;
    }

    // range sum from l..r (O(log n))
    T sum(int l, int r) {
        if(l > r) return 0;
        if(l == 0) return sum(r);
        return sum(r) - sum(l - 1);
    }

    void work(const vector<T>& a) {
        for (int i = 0; i < n; i++) {
            set(i, a[i]);
        }
    }
};
