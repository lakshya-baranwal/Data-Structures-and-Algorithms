class BIT {
    int n;              // size of array
    vector<int> tree;   // internal BIT array

    int lowbit(int x) { return x & -x; }  // helper function

public:
    BIT(int n) {
        this->n = n;
        tree.assign(n + 1, 0);  // 1-based indexing
    }

    // add value 'val' at index 'idx' (O(log n))
    void add(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += lowbit(idx);
        }
    }

    // prefix sum from 1..idx (O(log n))
    int sum(int idx) {
        int res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= lowbit(idx);
        }
        return res;
    }

    // range sum from l..r (O(log n))
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
