template<typename T> struct ordered_multiset{
  pbds<pair<T,int>> ost;
  map<T,int> freq;

  void insert(T val) {
    ost.insert(make_pair(val, ++freq[val]));
  }
  void erase(T val) {
    if(freq[val] == 0) return;
    ost.erase(make_pair(val, freq[val]--));
  }
  // number of elements strictly smaller than val
  int order_of_key(T val) {
    return ost.order_of_key(make_pair(val, -1));
  }
  // k-th smallest element
  T find_by_order(int k) {
    return ost.find_by_order(k)->first;
  }
  // first index with element >= val
  int bisect_left(const T& val) {
    auto it = ost.lower_bound(make_pair(val, -1));
    return it == ost.end() ? ost.size() : ost.order_of_key(*it);
  }
  // first index with element > val
  int bisect_right(const T& val) {
    auto it = ost.lower_bound(make_pair(val, INT_MAX));
    return it == ost.end() ? ost.size() : ost.order_of_key(*it);
  }
  int size() const {
    return ost.size();
  }
  bool empty() const {
    return ost.empty();
  }
  void clear() {
        ost.clear();
        freq.clear();
  }
  T front() const {
    return find_by_order(0);
  }
  T back() const {
    return find_by_order(size() - 1);
  }
};
