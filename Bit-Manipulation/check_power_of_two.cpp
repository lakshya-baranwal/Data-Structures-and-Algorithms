#include <bits/stdc++.h>
using namespace std;

/*
    -------------------------------------------------------------
    Check if a Number is a Power of 2 (Bitwise Trick)
    -------------------------------------------------------------
    This function returns true if n is a power of 2, otherwise false.

    Idea:
    A power of 2 has exactly one set bit in its binary form.
    The `n &&` part ensures n is not zero.

    Time complexity: O(1)
    Space complexity: O(1)
*/

bool is_power_of_2(int n) {
    return n && !(n & (n - 1));
}
