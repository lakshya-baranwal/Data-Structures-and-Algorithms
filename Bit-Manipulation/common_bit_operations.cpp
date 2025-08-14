#include <bits/stdc++.h>
using namespace std;

// Utility: print binary representation of an integer
void pr_binary(int x) {
    for (int i = 31; i >= 0; i--)
        cout << ((x >> i) & 1);
    cout << '\n';
}
/*
    -------------------------------------------------------------
    Common Bit Manipulation Techniques
    -------------------------------------------------------------

    1. Find the Lowest Set Bit of an Integer
       --------------------------------------------------------
       Formula:
           bit = number & -number
       Idea:
       Two's complement representation of -number:
           The bit at the lowest set-bit position remains 1
           All less significant bits become 0
           All more significant bits are inverted
           AND with original number isolates that single lowest set bit.
       
       Time complexity: O(1)
       Space complexity: O(1)

    2. Unset the Lowest Set Bit
       ---------------------------------------------------------
       Formula:
           number = number - (number & -number)
       Idea:
       Subtract the isolated lowest set bit (from step 1) from the number.
       This clears that single 1-bit without affecting others.

       Time complexity: O(1)
       Space complexity: O(1)

    3. Set the i-th bit:
       ---------------------------------------------------------
       Formula: a | (1 << i)

       Idea:
       1 << i creates a mask with only the i-th bit set.
       OR (|) with 'a' ensures that bit becomes 1 while leaving other bits unchanged.

    4. Unset the i-th bit:
       ---------------------------------------------------------
       Formula: a & (~(1 << i))

       Idea:
       1 << i creates a mask with only the i-th bit set.
       ~ (NOT) inverts it: all bits become 1 except the i-th bit (0).
       AND (&) with 'a' forces that bit to 0 while keeping others intact.

    5. Toggle the i-th bit:
       ---------------------------------------------------------
       Formula: a ^ (1 << i)

       Idea:
       1 << i creates a mask with only the i-th bit set.
       XOR (^) flips the bit: 0 → 1, 1 → 0.

    Time complexity: O(1) for all
    Space complexity: O(1)
*/

// 1. Find the lowest set bit
int lowest_set_bit(int number) {
    return number & -number;
}

// 2. Unset the lowest set bit
int unset_lowest_set_bit(int number) {
    return number - (number & -number);
}

// 3. Set the i-th bit
int set_bit(int a, int i) {
    return a | (1 << i);
}

// 4. Unset the i-th bit
int unset_bit(int a, int i) {
    return a & (~(1 << i));
}

// 5. Toggle the i-th bit
int toggle_bit(int a, int i) {
    return a ^ (1 << i);
}


