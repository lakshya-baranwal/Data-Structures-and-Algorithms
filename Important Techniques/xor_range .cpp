#include <bits/stdc++.h>
using namespace std;

/*
    -------------------------------------------------------------
    XOR of a Range in O(1) Time:

    An efficient way to compute the XOR
    of all integers in a given range [l, r].
    
    1. Why this works:
    This happens because of how binary addition without carry (XOR)
    behaves — it cycles through a predictable pattern.

    
    2. XOR from l to r:
    If we know XOR(0..n), we can get XOR(l..r) using:

        XOR(l..r) = XOR(0..r) ^ XOR(0..l-1)

    This works because XOR has a self-canceling property:
        (A ^ B) ^ B = A
    -------------------------------------------------------------
*/

// Function to get XOR from 0 to n
int xor_0_n(int n) {
    int rem = n % 4;
    if (rem == 0) return n;
    if (rem == 1) return 1;
    if (rem == 2) return n + 1;
    return 0; // rem == 3
}

// Function to get XOR from l to r
int xor_range(int l, int r) {
    return xor_0_n(r) ^ xor_0_n(l - 1);
}
