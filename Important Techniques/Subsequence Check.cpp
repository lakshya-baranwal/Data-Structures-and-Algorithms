# To check if string t is a subsequence of string s.

# Build a 2D array nxt[i][c] where nxt[i][c] gives the next position of character c in s, starting from index i.
# Time Complexity - Preprocessing: O(n × 26), Query (per string t): O(|t|)

vector<vector<int>> build_nxt_array(string s) {
    int n = s.length();
    vector<vector<int>> nxt(n + 1, vector<int>(26, n));
    for (int i = n - 1; i >= 0; i--) {
        for (int c = 0; c < 26; c++) {
            nxt[i][c] = nxt[i + 1][c];
        }
        nxt[i][s[i] - 'a'] = i;
    }
    return nxt;
}

bool is_subsequence(const string &t, const vector<vector<int>> &nxt, int n) {
    int idx = 0;
    for (char ch : t) {
        if (nxt[idx][ch - 'a'] == n) return false;
        idx = nxt[idx][ch - 'a'] + 1;
    }
    return true;
}
