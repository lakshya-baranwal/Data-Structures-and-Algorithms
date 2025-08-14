#include <bits/stdc++.h>
using namespace std;

/*
    -------------------------------------------------------------
    Count Distinct Lowercase Characters Using Bitmask
    -------------------------------------------------------------

    This function counts how many different lowercase English
    letters ('a' to 'z') appear in the given string `s`.

    Idea:
    - We maintain an integer `mask` where each bit represents
      whether a letter has appeared in the string.
        bit 0 → 'a'
        bit 1 → 'b'
        ...
        bit 25 → 'z'

    - For each character, we set its corresponding bit using:
          mask |= (1 << (i - 'a'));

    Time complexity: O(n) for string length n.
    Space complexity: O(1) because we use only one integer mask.
*/

int countDistinctLetters(string &s) {
    int mask = 0; // 26-bit representation of letters
    for (char c : s) {
        mask |= (1 << (c - 'a'));
    }
    return __builtin_popcount(mask);
}
