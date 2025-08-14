#include <bits/stdc++.h>
using namespace std;

/*
    -------------------------------------------------------------
    Bit Manipulation Tricks: Lowest Set Bit & Unset Lowest Set Bit
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
*/

// Find the lowest set bit
int lowest_set_bit(int number) {
    return number & -number;
}

// Unset the lowest set bit
int unset_lowest_set_bit(int number) {
    return number - (number & -number);
}

