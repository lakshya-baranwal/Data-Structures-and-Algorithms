#include <bits/stdc++.h>
using namespace std;


// Count Palindromic Substrings
int countPalindromicSubstrings(string s) {
    int n = s.size();
    if (n == 0) return 0;

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0;
    // Length 1 substrings
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        count++;
    }
    // Length 2 substrings
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            count++;
        }
    }
    // Length >= 3
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                count++;
            }
        }
    }
    return count;
}
/* Time Complexity: O(n*n)
   Space Complexity: O(n*n) (can be reduced to O(n) with rolling array)
----------------------------------------------------------------------------------*/
// Longest Palindromic Substring
string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0, maxLen = 1;

    // All substrings of length 1
    for (int i = 0; i < n; i++) dp[i][i] = true;

    // Check substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }
    // Check lengths >= 3
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }
    return s.substr(start, maxLen);
}
/* Time Complexity: O(n*n)
   Space Complexity: O(n*n)
----------------------------------------------------------------------------------
----------------------------------------------------------------------------------*/


// Function to find the longest palindromic substring using expand-around-center

// Time Complexity: O(n^2)
// Space Complexity: O(1)
string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    auto expand = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    };

    for (int center = 0; center < n; center++) {
        expand(center, center);     // odd length palindromes
        expand(center, center + 1); // even length palindromes
    }

    return s.substr(start, maxLen);
}

// Function to count all palindromic substrings using expand-around-center

// Time Complexity: O(n^2)
// Space Complexity: O(1)
int countPalindromicSubstrings(string s) {
    int n = s.size();
    int count = 0;

    auto expand = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    };

    for (int center = 0; center < n; center++) {
        expand(center, center);     // odd length palindromes
        expand(center, center + 1); // even length palindromes
    }

    return count;
}
