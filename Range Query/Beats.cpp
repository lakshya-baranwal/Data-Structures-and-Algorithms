#define int long long
#define inf (int)1e18
#define mod 1000000007 //998244353

struct node{
    int mn, smn, sum, cnt, add, len;
};

class Seg {
public:
    int n; 
    vector<node> st;

    Seg(const vector<int> &a){
        n = a.size();
        st.resize(4*n);
        build(1, 0, n-1, a);
    }

    void range_chmax(int l, int r, int x){
        range_chmax(1, 0, n-1, l, r, x);
    }

    int range_sum(int l, int r){
        return range_sum(1, 0, n-1, l, r);
    }

    void range_add(int l, int r, int x){
        range_add(1, 0, n-1, l, r, x);
    }
private:

    node merge(node &a, node &b){
        node res;
        res.add = 0;    
        if(a.mn < b.mn){
            res.mn = a.mn;
            res.cnt = a.cnt;
            res.smn = min(a.smn, b.mn);
        }
        else if(b.mn < a.mn){
            res.mn = b.mn;
            res.cnt = b.cnt;
            res.smn = min(b.smn, a.mn);
        }
        else{
            res.mn = a.mn;
            res.cnt = a.cnt+b.cnt;
            res.smn = min(a.smn, b.smn);
        }
        res.sum = a.sum + b.sum;
        res.len = a.len + b.len;
        return res; 
    }

    void apply_chmax(int p, int x){
        if(st[p].mn >= x) return;
        st[p].sum += (x - st[p].mn) * st[p].cnt;
        st[p].mn = x; 
    }
    void apply_add(int p, int x){
        st[p].mn += x;
        st[p].smn += x;
        st[p].sum += x*(st[p].len);
        st[p].add += x;
    }

    void push(int p){
        if(st[p].add != 0){
            apply_add(p<<1, st[p].add);
            apply_add(p<<1|1, st[p].add);
            st[p].add = 0;
        }
        apply_chmax(p<<1, st[p].mn);
        apply_chmax(p<<1|1, st[p].mn);
    }

    void build(int p, int l, int r, const vector<int> &a){
        if(l==r){
            st[p] = {a[l], inf, a[l], 1, 0, 1};
            return;
        }
        int m = (l+r)>>1;
        build(p<<1, l, m, a);
        build(p<<1|1, m+1, r, a);
        st[p] = merge(st[p<<1], st[p<<1|1]);
    }


    void range_chmax(int p, int l, int r, int L, int R, int x){
        if(r < L or l > R or st[p].mn >= x) return;

        if(L <= l and r <= R and st[p].smn > x){
            apply_chmax(p, x);
            return;
        }

        push(p);

        int m = (l+r)>>1;
        range_chmax(p<<1, l, m, L, R, x);
        range_chmax(p<<1|1, m+1, r, L, R, x);
        st[p] = merge(st[p<<1], st[p<<1|1]);
    }

    void range_add(int p, int l, int r, int L, int R, int x){
        if(r < L or l > R) return;
        if(L <= l and r <= R){
            apply_add(p, x);
            return;
        }

        push(p);
        int m = (l+r)>>1;
        range_add(p<<1, l, m, L, R, x);
        range_add(p<<1|1, m+1, r, L, R, x);
        st[p] = merge(st[p<<1], st[p<<1|1]);
    }
    int range_sum(int p, int l, int r, int L, int R){
        if(r < L or R < l) return 0;
        if(L <= l and r <= R) return st[p].sum;
        push(p);
        int m = (l+r)>>1;
        return range_sum(p<<1, l, m, L, R) + range_sum(p<<1|1, m+1, r, L, R);
    }
};
