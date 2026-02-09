// Counting inversions using fenwick tree (can also be done using other methods)
// time complexity: O(nlogn)
int count_inversions(vector<int> v) {
    int n = v.size();

    // coordinate compression
    map<int,int> mp;
    for (int x : v) mp[x];

    int id = 0;
    for (auto &p : mp)
        p.second = id++;

    BIT<int> bit(id);

    int inv = 0;

    for (int i = 0; i < n; i++) {
        int idx = mp[v[i]];    
        inv += i - bit.sum(idx); // greater elements already seen
        bit.add(idx, 1);
    }
    return inv;
}
