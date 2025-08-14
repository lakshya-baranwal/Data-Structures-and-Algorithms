#include <bits/stdc++.h>
using namespace std;

/*
    -------------------------------------------------------------
    Bit Manipulation Tricks — Competitive Programming Reference
    -------------------------------------------------------------
    Each function below includes:
      • What it does   — the purpose in plain English.
      • How it works   — the core bitwise idea (no long examples).
      • Notes          — edge cases or constraints when relevant.

    Assumes 32-bit int/unsigned unless noted. Prefer unsigned for
    pure bit-twiddling when sign is irrelevant.
*/

/* 1) Max without branching
   What it does: Returns max(a, b) without if/else or branches.
   How it works: Builds a mask from (a < b) and conditionally selects bits via XOR.
   Notes: Relies on two’s complement (-x) and bool→int promotion (0/1). */
int max_no_branch(int a, int b) {
    return a ^ ((a ^ b) & -(a < b));
}

/* 2) Min without branching
   What it does: Returns min(a, b) without branching.
   How it works: Same trick as max, but selects the other operand.
   Notes: Same assumptions as above. */
int min_no_branch(int a, int b) {
    return b ^ ((a ^ b) & -(a < b));
}

/* 3) Negate without branching
   What it does: Computes -x using bit ops.
   How it works: Two’s complement: ~x + 1 equals -x.
   Notes: Well-defined for all signed ints in two’s complement (standard practice). */
int negate_no_branch(int x) {
    return ~x + 1;
}

/* 4) Absolute value without branching
   What it does: Computes |x| with no branches.
   How it works: mask = x>>31 is all 1s for negative, else 0; (x^mask)-mask removes the sign.
   Notes: Beware INT_MIN: |INT_MIN| overflows in signed int. Use 1LL * etc. if needed. */
int abs_no_branch(int x) {
    int mask = x >> 31;
    return (x ^ mask) - mask; // UB for INT_MIN on platforms where -INT_MIN overflows
}

/* 5) Set the p-th bit to {0,1}
   What it does: Forces bit p of n to ‘bit’ (0 or 1).
   How it works: Clear target bit with ~(1<<p), then OR the desired bit in place. */
int set_bit_to(int n, int p, int bit) {
    return (n & ~(1 << p)) | ((bit & 1) << p);
}

/* 6) Integer square root (floor)
   What it does: Returns floor(sqrt(n)) for non-negative n without using sqrt().
   How it works: Binary search on the answer; mid*mid ≤ n advances low bound.
   Notes: O(log n); use 64-bit for mid*mid to avoid overflow. */
int int_sqrt(int n) {
    if (n <= 0) return 0;
    int lo = 1, hi = min(n, 46340), ans = 0; // 46340^2 < 2^31
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (1LL * mid * mid <= n) { ans = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    return ans;
}

/* 7) Integer cube root (floor)
   What it does: Returns floor(cuberoot(n)) for non-negative n.
   How it works: Binary search; mid^3 ≤ n.
   Notes: O(log n). Upper bound 1290 since 1290^3 < 2^31. */
int int_cbrt(int n) {
    if (n <= 0) return 0;
    int lo = 1, hi = min(n, 1290), ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (1LL * mid * mid * mid <= n) { ans = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    return ans;
}

/* 8) floor(log2(n))
   What it does: Returns ⌊log2(n)⌋ for n>0.
   How it works: Uses count-leading-zeros; pos = 31 - clz(n).
   Notes: n must be > 0; clz(0) is undefined. */
int log2_int(unsigned int n) {
    return 31 - __builtin_clz(n);
}

/* 9) Reverse all 32 bits
   What it does: Bitwise mirror of a 32-bit unsigned integer.
   How it works: Swap 1-bit groups, then 2-bit, 4-bit, 8-bit, 16-bit via masks/shifts.
   Notes: For 64-bit, extend masks and add a 32-step. */
unsigned int reverse_bits32(unsigned int n) {
    n = ((n >> 1) & 0x55555555u) | ((n & 0x55555555u) << 1);
    n = ((n >> 2) & 0x33333333u) | ((n & 0x33333333u) << 2);
    n = ((n >> 4) & 0x0F0F0F0Fu) | ((n & 0x0F0F0F0Fu) << 4);
    n = ((n >> 8) & 0x00FF00FFu) | ((n & 0x00FF00FFu) << 8);
    n = (n >> 16) | (n << 16);
    return n;
}

/* 10) Reverse bits on [L, R]
   What it does: Reverses the bits from index L to R inclusive (0 = LSB).
   How it works: Two-pointer swap: flip both ends when they differ; move inward.
   Notes: O(R-L+1); bounds must be valid for the word width. */
unsigned int reverse_bits_segment(unsigned int n, int L, int R) {
    while (L < R) {
        unsigned int bL = (n >> L) & 1u, bR = (n >> R) & 1u;
        if (bL != bR) n ^= (1u << L) | (1u << R);
        ++L; --R;
    }
    return n;
}

/* 11) Fast modulus for power-of-two divisors
   What it does: Computes x % p when p is a power of two.
   How it works: x & (p-1) is equivalent to modulus for p = 2^k.
   Notes: Requires p != 0 and p is a power of two. */
unsigned int fast_mod_pow2(unsigned int x, unsigned int p) {
    return x & (p - 1);
}

/* 12) Fast modulus by arbitrary constant (Barrett-style)
   What it does: Computes x % m faster when m is fixed and many queries occur.
   How it works: Precompute mu = floor(2^64 / m); use a 128→64 reduction approximation.
   Notes: For 64-bit platforms. For 32-bit, adapt types accordingly; not for cryptographic use. */
uint64_t barrett_reduce(uint64_t x, uint64_t m, unsigned __int128 mu) {
    // q ≈ floor(x / m) via high bits of x * mu / 2^64
    unsigned __int128 q = (unsigned __int128)x * mu >> 64;
    uint64_t r = x - (uint64_t)q * m;
    if (r >= m) r -= m;
    return r;
}
// Helper to precompute mu: mu = floor(2^64 / m)
unsigned __int128 barrett_mu(uint64_t m) {
    return ((unsigned __int128)~(uint64_t)0 + 1) / m; // 2^64 / m
}

/* 13) Next higher power of 2
   What it does: Smallest power of two >= n (for n>0); returns 1 for n==0.
   How it works: Propagate highest 1 downward by OR-shifts, then add 1.
   Notes: For large n near 2^32, watch overflow if using 32-bit unsigned. */
unsigned int next_power_of_2(unsigned int n) {
    if (n == 0) return 1u;
    --n;
    n |= n >> 1;  n |= n >> 2;  n |= n >> 4;
    n |= n >> 8;  n |= n >> 16;
    return n + 1;
}

/* 14) Previous (<= n) power of 2
   What it does: Largest power of two ≤ n; returns 0 for n==0.
   How it works: Uses position of highest set bit.
   Notes: clz(0) undefined; we check n==0 first. */
unsigned int prev_power_of_2(unsigned int n) {
    if (n == 0) return 0u;
    return 1u << (31 - __builtin_clz(n));
}

/* 15) Interleave bits (Morton code, 16-bit inputs → 32-bit)
   What it does: Interleaves bits of (x, y) as x0,y0,x1,y1,... for Z-order curves.
   How it works: "Part" each number by spreading bits with masks/shifts, then interleave.
   Notes: Common in spatial indexing; adapt masks for wider inputs. */
unsigned int interleave_bits_16x2_to_32(unsigned int x, unsigned int y) {
    auto part1by1 = [](unsigned int n) {
        n &= 0x0000FFFFu;
        n = (n | (n << 8)) & 0x00FF00FFu;
        n = (n | (n << 4)) & 0x0F0F0F0Fu;
        n = (n | (n << 2)) & 0x33333333u;
        n = (n | (n << 1)) & 0x55555555u;
        return n;
    };
    return (part1by1(y) << 1) | part1by1(x);
}

/* 16) Next lexicographic bit permutation (same popcount)
   What it does: Next larger integer with the same number of 1-bits.
   How it works: Gosper’s hack: add lowest set-bit “carry”, then fix tail with shifts/divisions.
   Notes: If v is the largest permutation (ones are at MSB side), result may wrap to 0. */
unsigned int next_bit_permutation(unsigned int v) {
    unsigned int c = v & -v;
    unsigned int r = v + c;
    return (((r ^ v) >> 2) / c) | r;
}

/* 17) Previous lexicographic bit permutation (same popcount)
   What it does: Next smaller integer with the same number of 1-bits.
   How it works: Mirror of Gosper: drop lowest set bit, then pack ones just below.
   Notes: If v is the smallest permutation (ones packed at LSB), result becomes 0. */
unsigned int prev_bit_permutation(unsigned int v) {
    unsigned int c = v & -v;
    unsigned int r = v - c;
    unsigned int t = v ^ r;
    t = (t >> 2) / c;
    return r | t;
}

/* 18) Enumerate all submasks of a mask (classic fast order)
   What it does: Iterates every submask of ‘mask’ in decreasing numeric order.
   How it works: sub = (sub-1) & mask walks all submasks in O(#submasks).
   Notes: Includes 0 and mask itself. */
void enumerate_submasks_decreasing(int mask, function<void(int)> visit) {
    for (int sub = mask;; sub = (sub - 1) & mask) {
        visit(sub);
        if (sub == 0) break;
    }
}

/* 19) Enumerate masks and submasks in lexicographic (increasing) order
   What it does: For all masks (0..(1<<n)-1), visits submasks in increasing order.
   How it works: Classic loop is decreasing; to get increasing, collect then reverse (cheap vs. correctness).
   Notes: For very large masks, consider on-the-fly stable order tailored to your use-case. */
void enumerate_masks_and_submasks_lex(int n, function<void(int,int)> visit) {
    const int LIM = 1 << n;
    for (int mask = 0; mask < LIM; ++mask) {
        vector<int> subs;
        for (int sub = mask;; sub = (sub - 1) & mask) {
            subs.push_back(sub);
            if (sub == 0) break;
        }
        sort(subs.begin(), subs.end()); // increasing lexical/numeric order
        for (int sub : subs) visit(mask, sub);
    }
}
