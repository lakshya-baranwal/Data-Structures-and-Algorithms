//Compute Longest Prefix Suffix (LPS) Array

vector<int> computeLPS(string &pat) {
        int n = pat.length();
        vector<int> lps(n, 0);
        int len = 0;

        for(int i = 1; i < n; ++i){
            while(len > 0 && pat[i] != pat[len]){
                len = lps[len -1];
            }
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
            }
        }
        return lps;
    }
