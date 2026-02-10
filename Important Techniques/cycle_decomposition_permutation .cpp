// the minimum number of swaps required to sort a permutation p of length n is given by:
// formula: s = n - c
// n is the length of the permutation
// c is the number of disjoint cycles in the permutation

// when we swap two elements in a permutation:
// if the elements are in the same cycle then the swap breaks that cycle into two different cycles
// if the elements are in the different cycle then the swap merges them into one cycle

// the cost to sort a cycle of size k is fixed at k-1 swaps
// total cost = (k1-1)+(k2-1)+...+(km-1) = (k1+k2+k3+...+km) - (1+1+...+1) = n - c

int min_swaps(vector<int>& arr) { // 1-based indexing
    int n = arr.size()-1;
    vector<pair<int,int>> a(n+1);
    for(int i = 1; i <= n; i++) a[i] = {arr[i], i};
    sort(a.begin()+1, a.end());

    vector<bool> visited(n+1, false);
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if(visited[i] || a[i].second == i) continue;

        int cycle_size = 0;
        int j = i;
        while(!visited[j]) {
            visited[j] = true;
            j = a[j].second;
            cycle_size++;
        }

        if(cycle_size > 0) ans += (cycle_size - 1);
    }
    return ans;
}
