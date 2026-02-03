using ll = long long;
const ll LAZY = 0;

struct node {
    ll x = 1e18;  ll idx=-1;  ll lazy=LAZY;  };

class Seg {
public:
    ll n;  vector<node> seg;
    Seg(ll n) {
        this->n = n;  seg.resize(4ll * n + 5ll);
    }
    // change here
    node combine(node &a, node &b) {
        node res = a;
        if(a.x > b.x) res = b;
        return res;
    }
    // change here
    node assign(ll x, ll idx) {
        node res;
        res.x = x;
        res.idx = idx;
        return res;
    }
    // change here
    void update_logic(ll idx, ll val) {
        seg[idx].x += val;
        seg[idx].lazy += val;
    }
    node no_overlap_return() {
        node res;
        res.x = 1e18;
        res.idx = -1;
        return res;
    }
    void propagate(ll idx, ll tl, ll tr) {
        if (seg[idx].lazy != LAZY and tl != tr) {

            update_logic(2 * idx, seg[idx].lazy);
            update_logic(2 * idx + 1, seg[idx].lazy);
            seg[idx].lazy = LAZY;
        }
    }
    void build_seg(ll idx, ll tl, ll tr, vector<ll> &a) {
        if (tl == tr) {
            seg[idx] = assign(a[tl], tl);
            return;
        }
        ll m = tl + ((tr - tl) >> 1ll);
        build_seg(2 * idx, tl, m, a);
        build_seg(2 * idx + 1, m + 1, tr, a);
        seg[idx] = combine(seg[2 * idx], seg[2 * idx + 1]);
    }
    node query_seg(ll idx, ll tl, ll tr, ll l, ll r) {
        propagate(idx, tl, tr);
        if (tl >= l and tr <= r) return seg[idx];
        if (tr < l or tl > r) return no_overlap_return();
        ll m = tl + ((tr - tl) >> 1ll);
        node left  = query_seg(2 * idx, tl, m, l, r);
        node right = query_seg(2 * idx + 1, m + 1, tr, l, r);
        return combine(left, right);
    }
    void update_seg(ll idx, ll tl, ll tr, ll l, ll r, ll x) {
        propagate(idx, tl, tr);
        if (tl > r or tr < l) return;
        if (tl >= l and tr <= r) {
            update_logic(idx, x);
            return;
        }
        ll m = tl + ((tr - tl) >> 1ll);
        update_seg(2 * idx, tl, m, l, r, x);
        update_seg(2 * idx + 1, m + 1, tr, l, r, x);
        seg[idx] = combine(seg[2 * idx], seg[2 * idx + 1]);
    }

    void build(vector<ll> &a) {
        build_seg(1, 1, n, a);
    }
    node query(ll l, ll r) {
        return query_seg(1, 1, n, l, r);
    }
    void update(ll l, ll r, ll val) {
        update_seg(1, 1, n, l, r, val);
    }
};
