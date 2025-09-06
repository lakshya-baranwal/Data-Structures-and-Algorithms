/*
*    Author: egoistlakshya
*/

// Aim for the most incredible goal your mind can conceive

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

/*
    -----------------------------------
    Coordinate Compression
    -----------------------------------
    Goal:
        Map large/inconvenient values into a small contiguous range [0..k-1]
        while preserving order.

    Usage:
        - Insert all values into the compressor with add_val(x).
        - Call build() to assign compressed indices.
        - Query with:
            get_cval(x) -> compressed value of original x
            get_val(id) -> original value from compressed id
            get_prev(x) -> compressed value of the largest number < x
            get_next(x) -> compressed value of the smallest number >= x

    Why add -mod*mod and mod*mod ?
        These act as artificial "sentinel" boundaries:
        - -mod*mod is smaller than any reasonable input.
        -  mod*mod is larger than any reasonable input.
        This ensures get_prev() and get_next() never go out of bounds,
        even if queries ask for numbers smaller than the minimum or
        larger than the maximum in the data.

    Complexity:
        - Insertion into map: O(n log n)
        - build(): O(n)
        - Queries: O(log n)
*/

struct coordinate_compression {
    vector<ll> reverse;            // reverse mapping: id -> original value
    map<ll,ll> compressed_val;     // original value -> compressed id
    ll x;

    // Insert a value into the compression set
    void add_val(ll v) { compressed_val[v]; }

    // Assign compressed ids in sorted order
    void build() {
        x = 0;
        for (auto &i : compressed_val) {
            reverse.emplace_back(i.first);
            i.second = x++;
        }
    }

    // Get compressed value of original
    inline ll get_cval(ll v) { return compressed_val[v]; }

    // Get original value from compressed
    inline ll get_val(ll id) { return reverse[id]; }

    // Get compressed id of the largest number < x
    ll get_prev(ll v) {
        auto it = compressed_val.upper_bound(v); // first > v
        it--;
        return it->second;
    }

    // Get compressed id of the smallest number >= x
    ll get_next(ll v) {
        auto it = compressed_val.lower_bound(v); // first >= v
        return it->second;
    }
};

void solve() {
    int n; cin >> n;
    
    coordinate_compression cc;
    vector<ll> a;

    // Add sentinel values for safe boundary queries
    cc.add_val(-mod*mod);
    cc.add_val(mod*mod);

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        a.emplace_back(x);
        cc.add_val(x);
    }
    cc.build();

    for (auto &i : a) {
        ll cval = cc.get_cval(i);
        cout << cval << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();

    return 0;
}
