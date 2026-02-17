struct node {
    int x;
    int idx;
};

struct seg_min {
    int n;
    vector<node> st;

    seg_min(const vector<int> &a) {
        n = (int) a.size() - 1;
        st.assign(4 * n + 5, {inf, -1});
        build(1, 1, n, a);
    }

    void update(int idx, int val) {
        update(1, 1, n, idx, val);
    }

    node query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    node merge(node a, node b) {
        if(a.x < b.x) return a;
        if(b.x < a.x) return b;
        return (a.idx < b.idx ? a : b);
    }

    void build(int p, int l, int r, const vector<int> &a) {
        if(l == r) {
            st[p] = {a[l], l};
            return;
        }
        int m = (l + r) >> 1;
        
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);

        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }
 
    void update(int p, int l, int r, int idx, int val) {
        if(l == r) {
            st[p] = {val, l};
            return;
        }
        int m = (l + r) >> 1;

        if(idx <= m) update(p << 1, l, m, idx, val);
        else update(p << 1 | 1, m + 1, r, idx, val);

        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }

    node query(int p, int tl, int tr, int l, int r) {
        if(r < tl || tr < l) return {inf, -1};
        if(l <= tl and tr <= r) return st[p];

        int m = (tl + tr) >> 1;

        return merge(query(p << 1, tl, m, l, r), query(p << 1 | 1, m + 1, tr, l, r));
    }
};

struct seg_max {
    int n;
    vector<node> st;

    seg_max(const vector<int> &a) {
        n = (int) a.size();
        st.assign(4 * n + 5, {-inf, -1});
        build(1, 1, n, a);
    }

    void update(int idx, int val) {
        update(1, 1, n, idx, val);
    }

    node query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    node merge(node a, node b) {
        if(a.x > b.x) return a;
        if(b.x > a.x) return b;
        return (a.idx > b.idx ? a : b);
    }

    void build(int p, int l, int r, const vector<int> &a) {
        if(l == r) {
            st[p] = {a[l], l};
            return;
        }
        int m = (l + r) >> 1;
        
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);

        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }
 
    void update(int p, int l, int r, int idx, int val) {
        if(l == r) {
            st[p] = {val, l};
            return;
        }
        int m = (l + r) >> 1;

        if(idx <= m) update(p << 1, l, m, idx, val);
        else update(p << 1 | 1, m + 1, r, idx, val);

        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }

    node query(int p, int tl, int tr, int l, int r) {
        if(r < tl || tr < l) return {-inf, -1};
        if(l <= tl and tr <= r) return st[p];

        int m = (tl + tr) >> 1;

        return merge(query(p << 1, tl, m, l, r), query(p << 1 | 1, m + 1, tr, l, r));
    }
};
