#include <bits/stdc++.h>
using namespace std;

/*
    -------------------------------------------------------------
    Count Set Bits using Brian Kernighan's Algorithm
    -------------------------------------------------------------

    This function counts the number of 1-bits (set bits) in the
    binary representation of a positive integer n.

    Idea:
    The trick `n & (n - 1)` unsets the rightmost set bit in n.

    Time complexity: O(k) where k is the number of set bits
                     (faster than O(log n) bit-by-bit checking).
    Space complexity: O(1).
*/

int count_set_bits(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n = n & (n - 1); // remove the rightmost set bit
    }
    return cnt;
}
