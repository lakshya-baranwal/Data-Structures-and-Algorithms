/*
*  Author: _CrazyForCode_
*  Modified by : egoistlakshya
*/
struct mint {
    static int mod;
    int x;

    mint() : x(0) {}
    mint(long long v) {
        v %= mod;
        if (v < 0) v += mod;
        x = int(v);
    }

    static void set_mod(int m) { mod = m; }

    int val() const { return x; }

    // unary ops
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    // arithmetic
    mint& operator+=(const mint& b) {
        x += b.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& b) {
        x -= b.x;
        if (x < 0) x += mod;
        return *this;
    }
    mint& operator*=(const mint& b) {
        x = int((__int128)x * b.x % mod);
        return *this;
    }
    mint& operator/=(const mint& b) {
        return *this *= b.inv();
    }

    // power & inverse
    mint power(long long n) const {
        mint res = 1, a = *this;
        while (n > 0) {
            if (n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
    mint inv() const {
        return power(mod - 2); // works if mod is prime
    }

    // comparison
    friend bool operator==(const mint& a, const mint& b) { return a.x == b.x; }
    friend bool operator!=(const mint& a, const mint& b) { return a.x != b.x; }

    // I/O
    friend std::ostream& operator<<(std::ostream& os, const mint& m) {
        return os << m.x;
    }
    friend std::istream& operator>>(std::istream& is, mint& m) {
        long long v;
        is >> v;
        m = mint(v);
        return is;
    }

    // non-member operators
    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
};
int mint::mod = 1000000007;
// Don't forget to check mod
