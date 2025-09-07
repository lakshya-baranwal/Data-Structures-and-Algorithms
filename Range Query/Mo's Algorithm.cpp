/*
    -----------------------------------
    Mo's Algorithm (Range Query Decomposition)
    -----------------------------------
    Idea:
        We are given an array and multiple offline queries 
        of the form [L, R]. Each query asks for some aggregate 
        function of the subarray a[L..R], such as:
            - XOR of the range
            - Sum of the range
            - Number of distinct elements
            - Frequency of a certain value
            - Mode Query
            - GCD / LCM (rarely, but possible with care)

        Mo's Algorithm sorts queries in a specific order 
        (usually by block of L, then by R), so that the 
        movement of the [L, R] window between consecutive 
        queries is minimized. This makes each array element 
        added/removed O(1) amortized.

    Implementation:
        - Preprocess block size = sqrt(n).
        - Sort queries by (L / BLOCK, then R).
        - Maintain a current window [currL, currR] and its 
          aggregate answer.
        - To process a new query [L, R], move currL/currR 
          step by step:
            - add(pos): include arr[pos] in the current answer
            - remove(pos): remove arr[pos] from the current answer
        - Store the result in ans[query.idx].

    Complexity:
        Sorting queries: O(q log q)
        Answering queries: O((n + q) * sqrt(n)) approx.

    --------------------
    Applications:
    --------------------
    1. Count distinct numbers in subarray.
    2. Frequency of values in ranges.
    3. XOR or sum queries over ranges.
    4. Problems where updates are NOT required (offline queries only).

    Note:
        - For some problems (like XOR), add/remove are symmetric.
        - For others (like freq count), we need auxiliary arrays 
          (e.g., freq[x]) to track counts.

    -----------------------------------
*/

struct Mo {
    struct Query {
        int l, r, idx;
    };

    int n;                          // array size
    int BLOCK;                      // block size ~ sqrt(n)
    vector<Query> qs;               // queries
    vector<long long> ans;          // answers for queries
    vector<int> &arr;               // reference to the array

    // user-defined functions
    function<void(int)> add;        // add position into current window
    function<void(int)> remove;     // remove position from current window
    function<long long()> get_answer; // retrieve current window's answer

    Mo(int n, vector<int> &arr) : n(n), arr(arr) {
        BLOCK = sqrt(n);
    }

    // add a query [l, r] with index idx
    void add_query(int l, int r, int idx) {
        qs.push_back({l, r, idx});
    }

    // process all queries
    void process() {
        ans.assign(qs.size(), 0);

        // classical Mo ordering (by block of L, then R)
        sort(qs.begin(), qs.end(), [&](const Query &a, const Query &b) {
            if (a.l / BLOCK != b.l / BLOCK) return a.l < b.l;
            return a.r < b.r;
        });

        int currL = 0, currR = -1;
        for (auto &q : qs) {
            while (currL > q.l) add(--currL);
            while (currR < q.r) add(++currR);
            while (currL < q.l) remove(currL++);
            while (currR > q.r) remove(currR--);
            ans[q.idx] = get_answer();
        }
    }
};
//------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------//


// Example Usage: XOR Queries
int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int currXor = 0;
    Mo mo(n, a);

    mo.add = [&](int pos) { currXor ^= a[pos]; };
    mo.remove = [&](int pos) { currXor ^= a[pos]; };
    mo.get_answer = [&]() { return (long long)currXor; };

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        --l, --r;
        mo.add_query(l, r, i);
    }

    mo.process();

    for (int i = 0; i < q; i++) cout << mo.ans[i] << "\n";
}

// Example Usage: Distict Count Queries 
vector<int> freq(1e6+5, 0);
int distinct = 0;

mo.add = [&](int pos) {
    if (++freq[a[pos]] == 1) distinct++;
};
mo.remove = [&](int pos) {
    if (--freq[a[pos]] == 0) distinct--;
};
mo.get_answer = [&]() { return (long long)distinct; };

