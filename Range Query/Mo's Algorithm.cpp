#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int BLOCK;

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const { // If I ever compare two Query objects using <, use this function
        if (l / BLOCK != other.l / BLOCK)
            return l / BLOCK < other.l / BLOCK;
        return ((l / BLOCK) & 1) ? (r < other.r) : (r > other.r);
    }
    /* Z-ordering (also called Hilbert-style ordering) is a heuristic technique used in Mo’s Algorithm to improve the
     runtime by minimizing the number of movements of the two pointers (l and r) during query processing.
     Odd blocks → sort r in increasing order.
     Even blocks → sort r in decreasing order.
     This creates a Z-shaped (zig-zag) order of queries → hence the name.
    */
    // More about Z-ordering : https://codeforces.com/blog/entry/61203
    
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
    BLOCK = sqrt(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
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
