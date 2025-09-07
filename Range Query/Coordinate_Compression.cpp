/*
    -----------------------------------
    Coordinate Compression (1D Array)
    -----------------------------------
    Goal:
        Replace large values with small consecutive integers 
        while preserving relative order.

    Idea:
        1. Insert all values into a map (sorted automatically).
        2. Assign a new ID to each unique value (1, 2, 3, ...).
        3. Replace each element with its compressed value.

    Complexity:
        Building map: O(n log n)
        Replacing: O(n log n)
*/

// Coordinate compression (1-based indexing)
void coordinateCompress(vector<long long>& a) {
    int n = (int)a.size() - 1; // ignore index 0
    map<long long, long long> mp;

    // Step 1: insert into map
    for (int i = 1; i <= n; i++) mp[a[i]]++;

    // Step 2: assign compressed IDs
    long long x = 1;
    for (auto &i : mp) mp[i.first] = x++;

    // Step 3: replace original values
    for (int i = 1; i <= n; i++) a[i] = mp[a[i]];
}

// Other efficient method
void coordinateCompress(vector<long long> &a){
   vector<int> vals = a;
   sort(vals.begin(), vals.end());
   vals.erase(unique(vals.begin(), vals.end()), vals.end());
   for (auto &x : a) {
      x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
   }
}

